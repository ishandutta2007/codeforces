#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=(1<<17);
int arra[MAXN], arrb[MAXN], deltas[MAXN], cums[MAXN];
int segmenttreemax[MAXN*2], segmenttreemin[MAXN*2];
int smin(int first, int last, int begin, int end, int idx){
    if(first<=begin&&end<=last){
        return segmenttreemin[idx];
    }
    if(end<=first||last<=begin){
        return numeric_limits<int>::max();
    }
    int mid=(begin+end)/2;
    return min(smin(first,last,begin,mid,idx*2),smin(first,last,mid,end,idx*2+1));
}
int smin(int first, int last){
    return smin(first, last, 0, MAXN, 1);
}
int smax(int first, int last, int begin, int end, int idx){
    if(first<=begin&&end<=last){
        return segmenttreemax[idx];
    }
    if(end<=first||last<=begin){
        return numeric_limits<int>::min();
    }
    int mid=(begin+end)/2;
    return max(smax(first,last,begin,mid,idx*2),smax(first,last,mid,end,idx*2+1));
}
int smax(int first, int last){
    return smax(first, last, 0, MAXN, 1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>arra[i];
    }
    for(int i=0;i<n;++i){
        cin>>arrb[i];
    }
    for(int i=0;i<n;++i){
        deltas[i]=arrb[i]-arra[i];
    }
    int cum=0;
    for(int i=0;i<n;++i){
        cum+=deltas[i];
        cums[i]=cum;
    }
    copy(cums,cums+n,segmenttreemax+MAXN);
    copy(cums,cums+n,segmenttreemin+MAXN);
    for(int i=MAXN-1;i>0;--i){
        segmenttreemax[i]=max(segmenttreemax[i*2],segmenttreemax[i*2+1]);
    }
    for(int i=MAXN-1;i>0;--i){
        segmenttreemin[i]=min(segmenttreemin[i*2],segmenttreemin[i*2+1]);
    }
    for(int j=0;j<q;++j){
        int l,r;
        cin>>l>>r;
        --l;
        int first=(l==0?0:cums[l-1]);
        int last=cums[r-1];
        if(first!=last){
            cout<<"-1\n";
        }
        else {
            int mini=smin(l,r);
            if(mini<first){
                cout<<"-1\n";
            }
            else {
                int maxi=smax(l,r);
                cout<<maxi-first<<'\n';
            }
        }
    }
}