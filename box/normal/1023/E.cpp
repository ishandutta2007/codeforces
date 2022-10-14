// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

mt19937 rng(108616);

int n;
bool isOnPath(int r, int c,bool mo){
    if(r==n+1)return 0;
    if(c==n+1)return 0;
    if((r==n&&c==n)||(r==1&&c==1))return 1;
    if(mo){
        cout<<"? 1 1 "<<r<<' '<<c<<endl;
        string s;cin>>s;
        return s=="YES";
    }else{
        cout<<"? "<<r<<' '<<c<<' '<<n<<' '<<n<<endl;
        string s;cin>>s;
        return s=="YES";
    }
}
int Ax,Ay;
string firhaf(){
    int x=1,y=1;
    string ans;
    while(x+y!=n+1){
        if(isOnPath(x+1,y,0))ans+='D',x++;
        else ans+='R',y++;
    }
    Ax=x;Ay=y;
    return ans;
}
string sechaf(){
    int x=n,y=n;
    string ans;
    while(x+y!=n+1){
        if(isOnPath(x,y-1,1))ans+='R',y--;
        else ans+='D',x--;
    }
    assert(x==Ax&&y==Ay);
    reverse(all(ans));
    return ans;
}

signed main() {
    cin>>n;
    string ans=firhaf();
    ans+=sechaf();
    cout<<"! "<<ans<<endl;
}