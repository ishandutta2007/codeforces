#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
vector <int> v[2000005];
unordered_map <int,int> val_id;
set <int> val;
int a[400005],id_val[2000005],belong[400005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,x=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!val_id[a[i]]) id_val[++x]=a[i],val_id[a[i]]=x,val.insert(a[i]);
            belong[i]=val_id[a[i]],v[val_id[a[i]]].push_back(i);
        }
        int q;
        cin>>q;
        for(int i=1,t;i<=q;i++){
            scanf("%d",&t);
            if(t==1){
                int pos,h;
                scanf("%d%d",&pos,&h);
                if(!val_id[h]) id_val[++x]=h,val_id[h]=x,val.insert(h);
                belong[pos]=val_id[h],v[val_id[h]].push_back(pos);
            }
            else if(t==2){
                int pos;
                scanf("%d",&pos);
                printf("%d\n",id_val[belong[pos]]);
            }
            else{
                int l,r;
                scanf("%d%d",&l,&r);
                if(!val_id[r+1]) id_val[++x]=r+1,val_id[r+1]=x,val.insert(r+1);
                for(auto it=val.upper_bound((l+r)/2);it!=val.end()&&(*it)<=r;++it){
                    //cout<<"------"<<(*it)<<" "<<val_id[*it]<<endl;
                    if(v[val_id[*it]].size()>v[val_id[r+1]].size()){
                        swap(val_id[*it],val_id[r+1]);
                        id_val[val_id[r+1]]=r+1;
                    }
                    for(auto temp:v[val_id[*it]]){
                        if(belong[temp]==val_id[*it]) belong[temp]=val_id[r+1],v[val_id[r+1]].push_back(temp);
                    }
                    val_id[*it]=0;
                }
                auto it=val.upper_bound((l+r)/2);
                while(it!=val.end()&&(*it)<=r) val.erase(it),it=val.upper_bound((l+r)/2);
                if(!val_id[l-1]) id_val[++x]=l-1,val_id[l-1]=x,val.insert(l-1);
                for(it=val.upper_bound((l+r)/2);;){
                    if(it==val.begin()) break;
                    --it;
                    //cout<<"######"<<(*it)<<" "<<val_id[*it]<<endl;
                    if((*it)<l) break;
                    if(v[val_id[*it]].size()>v[val_id[l-1]].size()){
                        swap(val_id[*it],val_id[l-1]);
                        id_val[val_id[l-1]]=l-1;
                    }
                    for(auto temp:v[val_id[*it]]){
                        if(belong[temp]==val_id[*it]) belong[temp]=val_id[l-1],v[val_id[l-1]].push_back(temp);
                    }
                    val_id[*it]=0;
                }
                it=val.upper_bound((l+r)/2);
                while(it!=val.begin()){
                    --it;
                    if((*it)<l) break;
                    val.erase(it),it=val.upper_bound((l+r)/2);
                }
            }
            //for(int j=1;j<=n;j++) cout<<id_val[belong[j]]<<" ";puts("");
        }
    }
    return 0;
}