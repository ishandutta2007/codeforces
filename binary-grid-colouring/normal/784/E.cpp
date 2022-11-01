#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int a1=a^b;
    int b1=c|d;
    int c1=b&c;
    int d1=a^d;
    int a2=a1&b1;
    int b2=c1|d1;
    cout<<(a2^b2)<<endl;
    return 0;
}