#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdbool>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
const int SIZE = 1e6+1;
ll one[SIZE], zero[SIZE], s[SIZE];
ll dif[SIZE];// dif[i] = one[i] - zero[i];
int main()
{
    ll n;
    char s[SIZE];
    scanf("%lld%s", &n, s);
 
    for (ll i = 1; i <= n; i++){
        
        one[i] += (s[i-1] == '1') + one[i - 1]; zero[i] += (s[i-1] == '0') + zero[i - 1];
        dif[i] = one[i] - zero[i];
    }
    //for(int i = 0; i < n; i++){printf("one[%d] = %lld, zero[%d] = %lld\n", i, one[i], i, zero[i]);}
    ll res = 0;
 
    /*for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (dif[i] - dif[j - 1] == 0){
                res = max((int)res, i - j + 1);
                break;
            }
        }
    }
    */
   map <ll, ll> first;// first[index] = first time dif[i] appeared
   //memset(first, -1, sizeof(first));
    for (ll i = n * (-1); i <=n; i++){
        first[i] = -1;
        //printf("%lld", dif[i]);   
    }
    first[0] = 0;
    for (ll i = 1;i <= n; i++){
       if (first[dif[i]] == -1){first[dif[i]] = i;}
       res = max(res, (i - first[dif[i]]));
   }
 
 
    printf("%lld\n", res);
    return 0;
    
}