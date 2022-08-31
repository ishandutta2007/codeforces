#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t-->0){
        int d;
        cin>>d;
        double D=d*d-4*d,r;
        if(D<0){cout<<"N\n";continue;}
        cout<<"Y";
        r=(d+sqrt(D))/2;
        printf(" %0.9f %0.9f\n",r,d-r);
    }
}