#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef complex<double> point;
#define MAXN 2005

point ps[MAXN];
bool mk[MAXN];

double dot(point a,point b) {return real(conj(a)*b);}

double cross(point a,point b) {return imag(conj(a)*b);}

int ccw(point a,point b,point c)
{
    b-=a,c-=a;
    if(cross(b, c)>0) return 1;
    if(cross(b, c)<0) return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        ps[i]=point(x,y);
    }
    string s;
    cin >> s;

    int ini=-1;
    for(int i=0;i<n;i++)
        if(ini==-1 || ps[i].real()<ps[ini].real())
            ini=i;

    mk[ini]=1;
    cout << ini+1 << ' ';
    for(int i=0;i<n-2;i++)
    {
        int v=1;
        if(s[i]=='L')
            v=-1;
        int next=-1;
        for(int j=0;j<n;j++)
            if(!mk[j] && (next==-1 || ccw(ps[ini],ps[next],ps[j])==v))
                next=j;
        ini=next;
        cout << ini+1 << ' ';
        mk[ini]=1;
    }
    for(int i=0;i<n;i++)
        if(!mk[i])
            cout << i+1 << ' ';
    cout << '\n';

    return 0;
}