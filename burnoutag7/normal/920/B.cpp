#include<bits/stdc++.h>
using namespace std;

int tests;
int n,t;
int l[1005],r[1005];
int pos;
vector<int> v;
int res[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>tests;
    while(tests--){
        pos=1;
        t=0;
        memset(res,0,sizeof(res));
        v.clear();

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l[i]>>r[i];
        }
        while(pos<=n||v.size()>0){
            t++;
            while(l[pos]==t&&pos<=n){
                v.push_back(pos);
                pos++;
            }
            if(v.size()>0){
                res[v[0]]=t;
                v.erase(v.begin());
            }
            for(int i=0;i<v.size();){
                if(t==r[v[i]]){
                    v.erase(v.begin()+i);
                }else{
                    i++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<res[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}