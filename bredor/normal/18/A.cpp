//  228

#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define PI 3.1415926535
#define INF INT_MAX
#define SPEED                       \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
  
// Aakash

int right(int a,int b,int c,int d,int e,int f){
    int d1=(a-c)*(a-c)+(b-d)*(b-d); 
    int d2=(c-e)*(c-e)+(d-f)*(d-f); 
    int d3=(a-e)*(a-e)+(b-f)*(b-f); 

    if(d1>0 && d2>0 && d3>0 && (d1==d2+d3 || d2==d1+d3 || d3==d1+d2))
    return 1;
    else
    return 0;

}

void solve(){
  int x1,y1,x2,y2,x3,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;

    if(right(x1,y1,x2,y2,x3,y3))
    {cout<<"RIGHT"; return;}

    if(right(x1-1,y1,x2,y2,x3,y3) || right(x1+1,y1,x2,y2,x3,y3) || right(x1,y1-1,x2,y2,x3,y3) || right(x1,y1+1,x2,y2,x3,y3))
    {cout<<"ALMOST"; return;}

    if(right(x1,y1,x2-1,y2,x3,y3) || right(x1,y1,x2+1,y2,x3,y3) || right(x1,y1,x2,y2-1,x3,y3) || right(x1,y1,x2,y2+1,x3,y3))
    {cout<<"ALMOST"; return;}

    if(right(x1,y1,x2,y2,x3-1,y3) || right(x1,y1,x2,y2,x3+1,y3) || right(x1,y1,x2,y2,x3,y3-1) || right(x1,y1,x2,y2,x3,y3+1))
    {cout<<"ALMOST"; return;}

    cout<<"NEITHER";

}

int32_t main() { 

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

     SPEED;
     int t=1;
    //  cin>>t;
     while(t--){
              solve();
     }
    return 0; 
}