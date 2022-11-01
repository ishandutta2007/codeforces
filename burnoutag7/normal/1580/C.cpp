#include<bits/stdc++.h>
using namespace std;

const int block=250;

int n,m,a[200005],b[200005],pref[200005],add[block+5][block+5];
vector<pair<int,int>> seg[200005];
pair<int,pair<int,int>> mod[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=m;i++){
        int typ,x;
        cin>>typ>>x;
        if(typ==1){
            seg[x].emplace_back(i,m+1);
        }else{
            seg[x].back().second=i;
        }
    }
    for(int i=1;i<=n;i++)if(a[i]+b[i]>block){
        for(auto &[l,r]:seg[i]){
            int x=l;
            while(1){
                x+=a[i];
                if(x<r)pref[x]++;
                else break;
                x+=b[i];
                if(x<r)pref[x]--;
                else{
                    pref[r]--;
                    break;
                }
            }
        }
    }else{
        for(auto &[l,r]:seg[i]){
            mod[l]=make_pair(a[i]+b[i],make_pair((a[i]+l)%(a[i]+b[i]),b[i]));
            mod[r]=make_pair(-a[i]-b[i],make_pair((a[i]+l)%(a[i]+b[i]),b[i]));
        }
    }
    for(int i=1;i<=m;i++)pref[i]+=pref[i-1];
    for(int i=1;i<=m;i++){
        auto &[len,p]=mod[i];
        auto &[x,y]=p;
        if(len>0){
            for(int j=0;j<y;j++)add[len][(x+j)%len]++;
        }else if(len<0){
            len=-len;
            for(int j=0;j<y;j++)add[len][(x+j)%len]--;
        }
        for(int j=1;j<=block;j++){
            pref[i]+=add[j][i%j];
        }
        cout<<pref[i]<<'\n';
    }

    return 0;
}