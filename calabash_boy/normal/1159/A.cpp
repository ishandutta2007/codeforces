#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int sum[maxn];
int n;
char s[maxn];
int main(){
    cin>>n;
    cin>>s+ 1;
    int min_sum = 0;
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1];
        if (s[i] == '+')sum[i] ++;
        else sum[i] --;
        min_sum = min(min_sum,sum[i]);
    }
    cout<<sum[n] - min_sum<<endl;
    return 0;
}