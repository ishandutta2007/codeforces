#include <bits/stdc++.h>
using namespace std;
long long n,kol,z,x,y,a[1005];
pair<int,int> b[1005];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>z;
        if (z==1){
            cin>>x>>y;
            ++kol;
            b[kol].first=x; b[kol].second=y;
        } else {
            cin>>x>>y;
            bool t=false;
            for (int j=1;j<=kol;++j)
                a[j]=j;
            while (true){
                bool k=false;
                for (int j=1;j<=kol;++j)
                    for (int z=1;z<=kol;++z)
                if (j!=z && a[j]==x && a[z]!=x){
                        if (b[j].first>b[z].first && b[j].first<b[z].second){
                            k=true;
                            a[z]=x;
                        }  else
                        if (b[j].second>b[z].first && b[j].second<b[z].second) {
                            k=true;
                            a[z]=x;
                        }
                }
                if (!k) break;
            }
            if (a[y]==x) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}