#include<iostream>
#include<algorithm>
#include<string.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include <queue>
#define PI acos(-1.0)
const long long INF = 1e18+10;
const long long NINF = -INF - 1;
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int t=0;
    for(int i=0;i<n;i+=2)
    {
        char a=s[i],b=s[i+1];
        if(a=='a'&&b=='a') s[i+1]='b',t++;
        else if(a=='b'&&b=='b') s[i]='a',t++;
    }
    cout<<t<<endl;
    cout<<s<<endl;
    return 0;
}