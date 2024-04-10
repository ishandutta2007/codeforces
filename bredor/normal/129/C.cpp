//  228

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define pb push_back
#define ss second
#define ff first 
#define ub upper_bound
#define lb lower_bound
const ll M=1000000007;
#define inf 1000000000000000000
#define all(X) (X).begin(),(X).end()
#define infn -1000000000000000000
ll ncr(int n,int r){if(r>n)return 0;if(r > n - r) r = n - r;ll ans = 1;
int i;for(i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
ll power(ll x,ll n,ll m){if(n==0)return 1;else if(n%2==0)return (power(((x%m)*(x%m))%m,n/2,m))%m;else return ((x%m)*(power(x,n-1,m)%m))%m;}
int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={1,0,-1,1,0,-1,1,0,-1};
ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ 
ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;} 
// std::rotate(vis.begin(), vis.begin()+rotL, vis.end());//rotl=no of left ro
// std::rotate(vis.begin(), vis.begin()+vis.size()-rotR, vis.end());
//transform(str.begin(),str.end(),str.begin(),::tolower);//also "toupper"
// to_string(ll),stoll(string)
//  priority_queue <T, vector<T>, greater<T> > pq;
string binary(ll n,ll k){
if(n==0)
return "0";
string ans;
while(n>0){
if(n&1)
ans.pb('1');
else
ans.pb('0');
n=n>>1;
}
ll l=ans.length();
for(int j=1; j<=k-l; j++)
ans.pb('0');
reverse(ans.begin(),ans.end());
return ans;
}
bool is_prime(ll n){
if(n==1)
return 0;
for(ll i=2; i*i<=n; i++){
if(n%i==0)
return 0;
}
return 1;
}
ll sum_digit(ll n){
ll ans=0;
while(n>0){
ans+=(n%10);
n/=10;
}
return ans;
}
ll binary_to_decimal(string str){
ll ans=0,d=1;
for(int i=str.length()-1; i>=0; i--){
ans+=d*(str[i]-48);
d*=2;
}
return ans;
}
double round(double var){
double value = (ll)(var * 100 + .5);
return (double)value / 100;
}
char num[10][10];
ll f=0;
void fun(ll i,ll j,ll step){
// cout<<i<<" "<<j<<"\n";
if(step>7){
f+=1;
return;
}
if(i==0&&j==7){
f+=1;
return;
}

for(int i1=0; i1<9; i1++){

ll x=dx[i1]+i;
ll y=dy[i1]+j;

if(x<0||y<0||x>7||y>7){
continue;
}
if(x-step-1>=0&&num[x-step-1][y]=='S'){
continue;
}
if(x-step>=0&&num[x-step][y]=='S'){
continue;
}

fun(x,y,step+1);
}


}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
for(int i=0; i<8; i++){
for(int j=0; j<8; j++){
cin>>num[i][j];
}
}
fun(7,0,0);
if(f==0)
cout<<"LOSE";
else
cout<<"WIN";
return 0;
}