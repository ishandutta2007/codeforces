#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <tuple>
using namespace std;
// index, cost
//vector<pair<unsigned,unsigned>> fwd_min[100000];
//vector<pair<unsigned,unsigned>> rev_min[100000];
// timeindex, cityindex, costdelta
vector<tuple<unsigned,unsigned,unsigned>> fwd_delta;
unsigned fwd_bests[100000];
unsigned long long fwd_costs[1000000];
vector<tuple<unsigned,unsigned,unsigned>> rev_delta;
unsigned rev_bests[100000];
unsigned long long rev_costs[1000000];
vector<tuple<unsigned,unsigned,unsigned>> fwd_flights;
vector<tuple<unsigned,unsigned,unsigned>> rev_flights;
/*template <typename Pred>
unsigned ternary_search(unsigned low, unsigned high, Pred test){

}*/
constexpr auto max_u=numeric_limits<unsigned>::max();
constexpr auto max_ull=numeric_limits<unsigned long long>::max();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n,m,k;
    cin>>n>>m>>k;
    for(unsigned i=0;i<m;++i){
        unsigned d,f,t,c;
        cin>>d>>f>>t>>c;
        --d;
        if(t==0){ // fwd flight
            fwd_flights.emplace_back(d,f-1,c);


            //fwd_min[f-1].emplace_back(d,c);
        }
        else{
            rev_flights.emplace_back(d,t-1,c);

            //rev_min[t-1].emplace_back(d,c);
        }
    }
    sort(fwd_flights.begin(),fwd_flights.end(),[](const tuple<unsigned,unsigned,unsigned>& a, const tuple<unsigned,unsigned,unsigned>& b){
        return get<0>(a)<get<0>(b);
    });
    sort(rev_flights.begin(),rev_flights.end(),[](const tuple<unsigned,unsigned,unsigned>& a, const tuple<unsigned,unsigned,unsigned>& b){
        return get<0>(a)>get<0>(b);
    });
    fill_n(fwd_bests,n,numeric_limits<unsigned>::max());
    fill_n(rev_bests,n,numeric_limits<unsigned>::max());
    for(auto& flight:fwd_flights){
        if(fwd_bests[get<1>(flight)]>get<2>(flight)){
            unsigned delta=((fwd_bests[get<1>(flight)]==max_u)?max_u:(fwd_bests[get<1>(flight)]-get<2>(flight)));
            fwd_bests[get<1>(flight)]=get<2>(flight);
            fwd_delta.emplace_back(get<0>(flight),get<1>(flight),delta);
        }
    }
    for(auto& flight:rev_flights){
        if(rev_bests[get<1>(flight)]>get<2>(flight)){
            unsigned delta=((rev_bests[get<1>(flight)]==max_u)?max_u:(rev_bests[get<1>(flight)]-get<2>(flight)));
            rev_bests[get<1>(flight)]=get<2>(flight);
            rev_delta.emplace_back(get<0>(flight),get<1>(flight),delta);
        }
    }
    {
        fwd_costs[999999]=accumulate(fwd_bests,fwd_bests+n,0ull,[](unsigned long long prev_val,unsigned curr){
            if(prev_val==max_ull || curr==max_u)return max_ull;
            return prev_val+curr;
        });
        auto it=fwd_delta.crbegin();
        for(unsigned i=999998;i!=max_u;--i){
            fwd_costs[i]=fwd_costs[i+1];
            while(it!=fwd_delta.crend()&&get<0>(*it)>i){
                if(fwd_costs[i]==max_ull || get<2>(*it)==max_u)fwd_costs[i]=max_ull;
                else fwd_costs[i]=fwd_costs[i]+get<2>(*it);
                ++it;
            }
        }
    }
    {
        rev_costs[0]=accumulate(rev_bests,rev_bests+n,0ull,[](unsigned long long prev_val,unsigned curr){
            if(prev_val==max_ull || curr==max_u)return max_ull;
            return prev_val+curr;
        });
        auto it=rev_delta.crbegin();
        for(unsigned i=1;i!=1000000;++i){
            rev_costs[i]=rev_costs[i-1];
            while(it!=rev_delta.crend()&&get<0>(*it)<i){
                if(rev_costs[i]==max_ull || get<2>(*it)==max_u)rev_costs[i]=max_ull;
                else rev_costs[i]=rev_costs[i]+get<2>(*it);
                ++it;
            }
        }
    }
    /*for(unsigned i=0;i<20;++i){
        cout<<fwd_costs[i]<<' '<<rev_costs[i]<<endl;
    }*/
    unsigned long long best=max_ull;
    for(unsigned i=1;i+k<1000000;++i){
        if(fwd_costs[i-1]==max_ull||rev_costs[i+k]==max_ull)continue;
        best=min(best,fwd_costs[i-1]+rev_costs[i+k]);
    }
    if(best==max_ull)cout<<"-1"<<endl;
    else cout<<best<<endl;
    /*for(unsigned i=0;i<n;++i){
        sort(fwd_min[i].begin(),fwd_min[i].end(),[](const pair<unsigned,unsigned>& a, const pair<unsigned,unsigned>& b){
            return a.first<b.first;
        });
        sort(rev_min[i].begin(),rev_min[i].end(),[](const pair<unsigned,unsigned>& a, const pair<unsigned,unsigned>& b){
            return a.first>b.first;
        });
        accumulate(fwd_min[i].begin(),fwd_min[i].end(),numeric_limits<unsigned>::max(),[](unsigned prev_best, const pair<unsigned,unsigned>& x){
            return x.second=min(x.second,prev_best);
        });
        accumulate(rev_min[i].begin(),rev_min[i].end(),numeric_limits<unsigned>::max(),[](unsigned prev_best, const pair<unsigned,unsigned>& x){
            return x.second=min(x.second,prev_best);
        });
    }
    auto res=ternary_search(low,high,[n](const unsigned val){
        auto fwd_price=accumulate(fwd_min,fwd_min+n,0ull,[this_index=val](unsigned long long prev_price, const vector<pair<unsigned,unsigned>>& x){
            auto it=upper_bound(x.crbegin(),x.crend(),this_index,[](const unsigned this_index, const pair<unsigned,unsigned>& y){
                return this_index>y.first;
            });
            if(it==x.crend())return numeric_limits<unsigned long long>::max();
            return prev_price+it->second;
        });
        auto rev_price=accumulate(rev_min,rev_min+n,0ull,[this_index=val+n](unsigned long long prev_price, const vector<pair<unsigned,unsigned>>& x){
            auto it=lower_bound(x.crbegin(),x.crend(),this_index,[](const unsigned this_index, const pair<unsigned,unsigned>& y){
                return this_index<y.first;
            });
            if(it==x.crend())return numeric_limits<unsigned long long>::max();
            return prev_price+it->second;
        });
        if(fwd_price==numeric_limits<unsigned long long>::max()||rev_price==numeric_limits<unsigned long long>::max())return numeric_limits<unsigned long long>::max();
        return fwd_price+rev_price;
    });*/

}