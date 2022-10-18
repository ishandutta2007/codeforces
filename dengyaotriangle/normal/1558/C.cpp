#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=2333;

int n;
int a[maxn];

vector<int> res;
void oper(int x){
    reverse(a+1,a+1+x);
    res.push_back(x);
}
int loc(int x){
    for(int i=1;i<=n;i++)if(a[i]==x)return i;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bool ok=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if((i^a[i])&1)ok=0;
        }
        if(!ok){
            cout<<"-1\n";
            continue;
        }
        res.clear();
        for(int i=n;i>=3;i-=2){
            int rp=loc(i),lp=loc(i-1);
            if(lp<rp){
                oper(rp);
                int nlp=loc(i-1);
                oper(nlp-1);
                oper(nlp+1);
                int z=loc(i);
                oper(z);oper(i);
            }else{
                oper(rp);oper(lp-1);oper(lp+1);
                int z=loc(i);
                oper(z);oper(i);
            }
        }
        cout<<res.size()<<'\n';
        for(int i:res)cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}