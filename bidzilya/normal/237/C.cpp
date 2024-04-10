#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

bool is_prime[1000001];
int a,b,k,ans;

bool check(int l){
    int cur=0;
    for (int i=a;i<a+l;i++)
        cur += is_prime[i];
    if (cur<k)return false;
    int left = a;
    int right = a+l-1;
    while (right<b){
        right++;
        cur += is_prime[right];
        cur -= is_prime[left];
        left++;
        if (cur<k)return false;
    }
    return true;
}

void sravn(int x){
    if (ans==-1 || x<ans)ans = x;
}

void binary(){
    int left = 1, right = b-a+1;
    while (left<=right){
        int middle = (left+right)/2;
        if (check(middle)){
            sravn(middle);
            right = middle-1;
        }else
            left = middle+1;
    }
}

int main(){
    for (int i=0;i<1000001;i++)
        is_prime[i]=true;
    for (int i=2;i<=1000000;i++)
        if (is_prime[i] && 1LL*i*i<=1000000)
            for (int j=i*i;j<=1000000;j+=i)
                is_prime[j]=false;
    is_prime[1] = false;
    cin >> a >> b >> k;
    ans = -1;
    binary();
    cout << ans << endl;
    return 0;
}