#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

struct T{
        int l,r;
};

const int N=(int)2e5+7;
int n,q,t[4*N];
set<int> unfreed;
vector<T> segs;

void upd(int v,int tl,int tr,int i,int x){
        if(tr<i||i<tl) return;
        if(tl==tr){
                t[v]=min(t[v],x);
                return;
        }
        int tm=(tl+tr)/2;
        upd(2*v,tl,tm,i,x);
        upd(2*v+1,tm+1,tr,i,x);
        t[v]=min(t[2*v],t[2*v+1]);
}

int get(int v,int tl,int tr,int l,int r){
        if(tr<l||r<tl) return (int)1e9+7;
        if(l<=tl&&tr<=r) return t[v];
        int tm=(tl+tr)/2;
        return min(get(2*v,tl,tm,l,r),get(2*v+1,tm+1,tr,l,r));
}

void freepos(int i){ /// to be done
        assert(unfreed.count(i));

        unfreed.erase(i);
}

void free(int l,int r){
        while(1){
                auto it=unfreed.lower_bound(l);
                if(it==unfreed.end()) break;
                if(*it>r) break;
                freepos(*it);
        }
}

void addseg(int l,int r){ /// can be done
        upd(1,1,n,l,r);
        segs.push_back({l, r});
}

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        for(int i=0;i<4*N;i++) t[i]=(int)1e9+7;

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }


        cin>>n>>q;
        for(int i=1;i<=n;i++){
                unfreed.insert(i);
        }
        while(q--){
                int t;
                cin>>t;
                if(t==0){
                        int l,r,x;
                        cin>>l>>r>>x;
                        if(x==0){
                                free(l,r);
                        }else{
                                addseg(l,r);
                        }
                }else{
                        int i;
                        cin>>i;
                        if(!unfreed.count(i)){
                                cout<<"NO\n";
                                continue;
                        }
                        bool ok=0;
                        int urm=n+1,ant=0;
                        auto it=unfreed.lower_bound(i+1);
                        if(it!=unfreed.end()){
                                urm=*it;
                        }
                        assert(it!=unfreed.begin());
                        {
                                it--;
                                if(it!=unfreed.begin()){
                                        it--;
                                        ant=*it;
                                }
                        }
                        if(get(1,1,n,ant+1,i)<urm){
                                cout<<"YES\n";
                        }else{
                                cout<<"N/A\n";
                        }
                }
        }

        return 0;
}