// non-lazy segment tree
// single update range query
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
// depth = N means that there is 2^N leaf nodes
// int may be changed to another type
template <typename T, size_t Depth>
struct segmenttree{
    T arr[1<<(Depth+1)];
    void update(size_t index, unsigned val){
        index+=(1<<Depth);
        arr[index]=val;
        bool sw=false;
        for(index>>=1;index>0;index>>=1,sw=!sw){
            if(sw)arr[index]=arr[index<<1]^arr[(index<<1)+1]; // updater function
            else arr[index]=arr[index<<1]|arr[(index<<1)+1];
        }
    }
    // past-the-end
    /*unsigned query(size_t index, size_t rb, size_t re, size_t ib, size_t ie){
        if(rb==ib&&re==ie){
            return T[index]; // querier function
        }
        unsigned ret=0; // additive identity
        size_t rm=(rb+re)>>1;
        if(ib<rm)ret+=query(index<<1,rb,rm,ib,min(rm,ie)); // coalesce function
        if(rm<ie)ret+=query((index<<1)+1,rm,re,max(ib,rm),ie); // coalesce function
        return ret;
    }*/
    // past-the-end
    unsigned query(){
        return arr[1];
    }
};

segmenttree<unsigned, 17> st;
int main(){
    unsigned n,m;
    cin>>n>>m;
    for(unsigned i=0;i<(1u<<n);++i){
        unsigned x;
        cin>>x;
        st.update(i,x);
    }
    for(unsigned i=0;i<m;++i){
        unsigned p,b;
        cin>>p>>b;
        --p;
        st.update(p,b);
        cout<<st.query()<<endl;
    }
}