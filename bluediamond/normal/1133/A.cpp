#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        string a,b;
        cin>>a>>b;
        int x=60*(10*(a[0]-'0')+a[1]-'0')+10*(a[3]-'0')+a[4]-'0';
        int y=60*(10*(b[0]-'0')+b[1]-'0')+10*(b[3]-'0')+b[4]-'0';
        int r=(x+y)/2;
        if(r/60<10) cout<<"0";
        cout<<r/60;
        cout<<":";
        if(r%60<10) cout<<"0";
        cout<<r%60<<"\n";
        return 0;
}
/**

**/