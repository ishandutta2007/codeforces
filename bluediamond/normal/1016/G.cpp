#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

vector<int> primes;

vector<pair<ll, int>> factor(ll value,vector<ll> relatives){
        vector<pair<ll, int>> sol;
        for(auto&p:primes){
                if(value%p==0){
                        int e=0;
                        while(value%p==0){
                                value/=p;
                                e++;
                        }
                        sol.push_back({p, e});
                }
        }
        if(value>1){
                ll low=0,high=(ll)1e9,solu=-1;
                while(low<=high){
                        ll i=(low+high)/2;
                        ll sqr=i*i;
                        if(sqr==value){
                                solu=i;
                                break;
                        }
                        if(sqr<value){
                                low=i+1;
                        }else{
                                high=i-1;
                        }
                }
                if(solu!=-1){
                        assert(solu*solu==value);
                        sol.push_back({solu, 2});
                        value=1;
                }
        }
        if(value>1){
                for(auto&relative:relatives){
                        ll g=__gcd(relative,value);
                        if(g>1&&g<value){
                                sol.push_back({g, 1});
                                sol.push_back({value/g, 1});
                                value=1;
                                break;
                        }
                }
        }
        if(value>1){
                sol.push_back({value, 1});
        }
        return sol;
}

void print(vector<pair<ll,int>> v){
        for(auto&it:v){
                cout<<" ---> "<<it.first<<" "<<it.second<<"\n";
        }
        cout<<"###############\n";
}

const int L=(int)1e6+7;


int n;
ll x,y;
bool isPrime[L];


signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        isPrime[2]=1;
        for(int i=3;i<L;i+=2){
                isPrime[i]=1;
        }
        for(int i=3;i*i<L;i+=2){
                if(isPrime[i]){
                        for(int j=i*i;j<L;j+=2*i){
                                isPrime[j]=0;
                        }
                }
        }

        for(int i=2;i<L;i++){
                if(isPrime[i]){
                        primes.push_back(i);
                }
        }


        cin>>n>>x>>y;
        vector<ll> relatives={x,y};
        vector<ll> v(n);
        for(auto&x:v){
                cin>>x;
                relatives.push_back(x);
        }

        vector<pair<ll, int>> fx=factor(x,relatives);
        vector<pair<ll, int>> fy=factor(y,relatives);

        if(y%x!=0){
                cout<<"0\n";
                return 0;
        }

        vector<ll> ps;
        vector<int> tx,ty;

        for(auto&it:fy){
                ll p=it.first;
                ll value=x;

                int times_x=0;
                int times_y=it.second;

                while(value%p==0){
                        value/=p;
                        times_x++;
                }

                if(times_x<times_y){
                        ps.push_back(p);
                        tx.push_back(times_x);
                        ty.push_back(times_y);
                }

        }

        int sz=(int)ps.size();
        assert(sz<=15);

        vector<int> mask_a,mask_b;

        for(auto&a:v){
                if(a%x==0){
                        int mask=0;
                        for(int i=0;i<sz;i++){
                                int times=0;
                                ll value=a;
                                while(value%ps[i]==0){
                                        times++;
                                        value/=ps[i];
                                }
                                if(times>tx[i]){
                                        mask+=(1<<i);
                                }
                        }
                        mask_a.push_back(mask);
                }
        }


        for(auto&b:v){
                if(y%b==0){
                        int mask=0;
                        for(int i=0;i<sz;i++){
                                int times=0;
                                ll value=b;
                                while(value%ps[i]==0){
                                        times++;
                                        value/=ps[i];
                                }
                                if(times<ty[i]){
                                        mask+=(1<<i);
                                }
                        }
                        mask_b.push_back(mask);
                }
        }
        vector<int> cnt(1<<sz,0);
        for(auto&b:mask_b){
                cnt[b]++;
        }
        for(int bit=0;bit<sz;bit++){
                for(int i=0;i<(1<<sz);i++){
                        if(i&(1<<bit)){
                                cnt[i]+=cnt[i^(1<<bit)];
                        }
                }
        }
        ll sol=0;
        for(auto&a:mask_a){
                sol+=cnt[(1<<sz)-1-a];
        }
        cout<<sol<<"\n";
}