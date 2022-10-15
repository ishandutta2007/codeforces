#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int x1,y1;
int x2,y2;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>x1>>y1;
        cin>>x2>>y2;
        int dx=abs(x2-x1);
        int dy=abs(y2-y1);
        int add=0;
        if(x1==x2 || y1==y2) add++;
        cout<<2*(dx+dy+2+add)<<"\n";
        return 0;
}
/**

**/