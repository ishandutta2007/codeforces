#include <bits/stdc++.h>

using namespace std;

const int N=10000;
const int MOD=1000000007;

int n,q;
int v[N+5];

vector<int>in[N+5];
vector<int>out[N+5];
int lst=0,nr[N+5];
bool este[N+5];

void f_in(int ind){
    for(auto c:in[ind]){
        int val=v[c];
        int start=min(lst,n-val);
        for(int j=start;j>=0;j--){
            if(nr[j]>0){
                este[j+val]=1;
                nr[j+val]+=nr[j];
                if(nr[j+val]>=MOD)
                    nr[j+val]-=MOD;
            }
        }
        lst=start+val;
    }
}

void f_out(int ind){
    for(auto c:out[ind]){
        int val=v[c];
        int a=0;
        int b=lst-val;
        for(int j=a;j<=b;j++){
            if(nr[j]>0){
                nr[j+val]-=nr[j];
                if(nr[j+val]<0)
                    nr[j+val]-=MOD;
            }
        }
        while(nr[lst]==0){
            lst--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lst=0;
    nr[0]=1;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        int st,dr;
        cin>>st>>dr>>v[i];
        in[st].push_back(i);
        out[dr+1].push_back(i);
    }
    for(int i=1;i<=n;i++){
        f_in(i);
        f_out(i);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(este[i]==1){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
        if(este[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
/**

**/