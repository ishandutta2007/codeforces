// non-lazy segment tree
// single update range query
#define MOD 1000000009
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
// depth = N means that there is 2^N leaf nodes
// int may be changed to another type
unsigned fib[300002];
unsigned fib_sum[300002];
template <typename T, size_t Depth, typename U>
struct segmenttree_lazy{
    // lazy param of node x has not been applied to node x and all nodes below it
    pair<T,U> arr[1<<(Depth+1)];
    unsigned effective_value(size_t index, size_t rb, size_t re){
        return (arr[index].first+(unsigned long long)arr[index].second.first*fib_sum[re-rb-1]+(unsigned long long)arr[index].second.second*(fib_sum[re-rb]-1))%MOD;
    }
    void propagate(size_t index, size_t rb, size_t re){
        auto prop_val=arr[index].second;
        arr[index].first=effective_value(index,rb,re);
        arr[index].second=make_pair(0ull,0ull);
        arr[index<<1].second.first+=prop_val.first;
        arr[index<<1].second.first%=MOD;
        arr[index<<1].second.second+=prop_val.second;
        arr[index<<1].second.second%=MOD;
        size_t advancer=((re-rb)>>1);
        arr[(index<<1)+1].second.first=(arr[(index<<1)+1].second.first+(unsigned long long)prop_val.first*fib[advancer]+(unsigned long long)prop_val.second*fib[advancer+1])%MOD;
        arr[(index<<1)+1].second.second=(arr[(index<<1)+1].second.second+(unsigned long long)prop_val.first*fib[advancer+1]+(unsigned long long)prop_val.second*fib[advancer+2])%MOD;
    }
    void update(size_t index, size_t rb, size_t re, size_t ib, size_t ie, unsigned valfirst, unsigned valsecond){
        //cout<<index<<' '<<rb<<' '<<re<<' '<<ib<<' '<<ie<<' '<<valfirst<<' '<<valsecond<<endl;
        if(rb==ib&&re==ie){
            arr[index].second.first+=valfirst; // update lazy storage
            arr[index].second.first%=MOD;
            arr[index].second.second+=valsecond;
            arr[index].second.second%=MOD;
            return;
        }
        size_t rm=(rb+re)>>1;
        if(ib<rm)update(index<<1,rb,rm,ib,min(rm,ie),valfirst,valsecond);
        size_t advancer=(max(ib,rm)-ib);
        if(rm<ie)update((index<<1)+1,rm,re,max(ib,rm),ie,((unsigned long long)valfirst*fib[advancer]+(unsigned long long)valsecond*fib[advancer+1])%MOD,((unsigned long long)valfirst*fib[advancer+1]+(unsigned long long)valsecond*fib[advancer+2])%MOD); // transformation for children
        arr[index].first=effective_value(index<<1,rb,rm)+effective_value((index<<1)+1,rm,re);
    }
    void update(size_t indexbegin, size_t indexend, unsigned valfirst, unsigned valsecond){
        update(1,0,1<<Depth,indexbegin,indexend,valfirst,valsecond);
    }
    void update_single(size_t index, T val){
        index+=(1<<Depth);
        for(;index>0;index>>=1){
            arr[index].first+=val; // updater function
            arr[index].first%=MOD;
        }
    }
    // past-the-end
    unsigned query(size_t index, size_t rb, size_t re, size_t ib, size_t ie){
        //cout<<index<<' '<<rb<<' '<<re<<' '<<ib<<' '<<ie<<endl;
        if(rb==ib&&re==ie){
            //return fib[re];
            //cout<<'a'<<arr[index].first<<' '<<arr[index].second.first<<' '<<arr[index].second.second<<endl;
            return effective_value(index,rb,re); // querier function
        }
        propagate(index,rb,re);
        unsigned ret=0; // additive identity
        size_t rm=(rb+re)>>1;
        if(ib<rm)ret+=query(index<<1,rb,rm,ib,min(rm,ie)); // coalesce function
        if(rm<ie)ret+=query((index<<1)+1,rm,re,max(ib,rm),ie); // coalesce function
        return ret%MOD;
    }
    // past-the-end
    unsigned query(size_t indexbegin, size_t indexend){
        return query(1,0,1<<Depth,indexbegin,indexend);
    }
};
segmenttree_lazy<unsigned,19,pair<unsigned,unsigned>> st;
int main(){
    fib_sum[0]=fib[0]=1;
    fib[1]=0;
    fib_sum[1]=fib[1]+fib_sum[0];
    for(int i=0;i<300000;++i){
        fib[i+2]=(fib[i+1]+fib[i])%MOD;
        fib_sum[i+2]=(fib[i+2]+fib_sum[i+1])%MOD;
    }
    unsigned n,m;
    cin>>n>>m;
    for(unsigned i=0;i<n;++i){
        unsigned x;
        cin>>x;
        st.update_single(i,x);
    }
    for(unsigned i=0;i<m;++i){
        unsigned tp,l,r;
        cin>>tp>>l>>r;
        --l;--r;
        if(tp==1){
            st.update(l,r+1,1,1);
        }
        else{
            cout<<st.query(l,r+1)<<endl;
        }
    }
}