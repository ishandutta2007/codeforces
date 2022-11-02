#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[1005];
int c[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        memset(c,0,sizeof(c));
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=2;;j++){
                if(a[i]%j==0){
                    if(mp.find(j)==mp.end())mp[j]=mp.size()+1;
                    c[i]=mp[j];
                    break;
                }
            }
        }
        cout<<mp.size()<<endl;
        for(int i=1;i<=n;i++){
            cout<<c[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}