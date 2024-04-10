#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int n,m;
string s;
int cnt1,cnt2;
int main(){
    ios::sync_with_stdio(0);
    int i,j;
    cin>>n;
    cin>>s;
    s=" "+s;
    for(i=1;i<=n;i++){
        if(s[i]=='('){
            if(cnt1<cnt2){
                cout<<0;
                cnt1++;
            }
            else{
                cout<<1;
                cnt2++;
            }
        }
        else{
            if(cnt1<cnt2){
                cout<<1;
                cnt2--;
            }
            else{
                cout<<0;
                cnt1--;
            }
        }
    }
    //
    return 0;
}