#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const double EPS = 1e-10;

int n, a, b;
double dp[MAXN];
double prr[MAXN], urr[MAXN];
int numa[MAXN], numb[MAXN];

void check(double mida, double midb){
    memset(dp, 0, sizeof dp);
    memset(numa, 0, sizeof numa);
    memset(numb, 0, sizeof numb);
    for(int i = 1; i<=n; i++){
        dp[i] = dp[i-1]; numa[i] = numa[i-1]; numb[i] = numb[i-1];
        if(dp[i] < dp[i-1]+prr[i]-mida-EPS){
            dp[i] = dp[i-1]+prr[i]-mida;
            numa[i] = numa[i-1]+1;
            numb[i] = numb[i-1];
        }
        if(dp[i] < dp[i-1]+urr[i]-midb-EPS){
            dp[i] = dp[i-1]+urr[i]-midb;
            numa[i] = numa[i-1];
            numb[i] = numb[i-1]+1;
        }
        if(dp[i] < dp[i-1]+prr[i]+urr[i]-prr[i]*urr[i]-mida-midb-EPS){
            dp[i] = dp[i-1]+prr[i]+urr[i]-prr[i]*urr[i]-mida-midb;
            numa[i] = numa[i-1]+1;
            numb[i] = numb[i-1]+1;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i<=n; i++) cin >> prr[i];
    for(int i = 1; i<=n; i++) cin >> urr[i];
    double la = 0, ha = 1, lb = 0, hb = 1;
    for(int x = 0; x<50; x++){
        double mida = (la+ha)/2;
        lb = 0, hb = 1;
        for(int y = 0; y<50; y++){
            double midb = (lb+hb)/2;
            check(mida, midb);
            if(numb[n] > b) lb = midb;
            else hb = midb;
        }
        if(numa[n] > a) la = mida;
        else ha = mida;
    }
    cout << dp[n]+la*a+lb*b << endl;
}