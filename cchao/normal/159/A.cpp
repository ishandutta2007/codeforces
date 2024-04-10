#include <iostream>
#include <set>
using namespace std;
typedef set<pair<string,string> > S;
#define mp make_pair
struct message
{
    string a,b;
    int t;
};
message m[1010];
int main()
{
    int n,d;
    cin >> n >> d;
    S ss;
    for(int k = 0;  k < n ; k++)
    {
        cin >> m[k].a >> m[k].b >> m[k].t;
        string a,b;
        for(int i = 0; i < k ; i++)
        {
            if(m[k].t - m[i].t > 0 &&
               m[k].t - m[i].t <= d &&
               m[k].b == m[i].a &&
               m[k].a == m[i].b)
               {
                   a = m[k].a;
                   b = m[k].b;
                   if(a > b) swap(a,b);
                   ss.insert(mp(a,b));
               }
        }
    }
    cout << ss.size() << endl;
    for(S::iterator it = ss.begin(); it != ss.end() ; it++)
    {
        cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}