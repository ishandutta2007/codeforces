#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 111111;
const int module = 1e9+7;

int n,k;
int a[N];
int res[1023];
int fact[N];

int pw(int x, int st)
{
    if (st==0)return 1;
    if (st%2==1)return (1LL*x*pw(x,st-1))%module;
    int t = pw(x,st/2);
    return (1LL*t*t)%module;
}

int C(int n,int k)
{
    if (k<0 || k>n)return 0;
    return (1LL*fact[n]*pw((1LL*fact[n-k]*fact[k])%module,module-2))%module;
}

bool happy(int x)
{
    while (x>0)
    {
        if (x%10!=4 && x%10!=7)return false;
        x/=10;
    }
    return true;
}

int main()
{
    fact[0] =1;
    for (int i=1; i<N; i++)
        fact[i] = (1LL*fact[i-1]*i)%module;
   // ifstream cin("input.txt");
    cin >> n >> k;
    for (int i=0; i<n; i++)cin >> a[i];
    sort(a, a+n);
    vector<int> h,ch;
    int uh = 0;
    for (int i=0; i<n; i++)
        if (happy(a[i]))
        {
            if (h.size()==0 || h[h.size()-1]!=a[i])
            {
                h.push_back(a[i]);
                ch.push_back(1);
            }else
                ch[h.size()-1]++;
        }else
            uh++;
    res[0]=1;
    for (int i=0; i<h.size(); i++)
        for (int j=h.size(); j>=1; j--)
            res[j] = (res[j] + (1LL*ch[i]*res[j-1])%module)%module;
    int ans = 0;
    for (int i=0; i<=min((int)h.size(),k); i++)
        ans = ((1LL*C(uh,k-i)*res[i])%module + ans)%module;
    cout << ans << endl;
    return 0;
}