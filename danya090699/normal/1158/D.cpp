#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
int po[sz][2], p[sz], us[sz], l[sz], r[sz];
long long S(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 1ll*(x2-x1)*(y2+y1)+1ll*(x3-x2)*(y3+y2)+1ll*(x1-x3)*(y1+y3);
}
bool comp(int a, int b)
{
    if(po[a][0]!=po[b][0]) return po[a][0]<po[b][0];
    else return po[a][1]<po[b][1];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        cin>>po[a][0]>>po[a][1];
        p[a]=a;
    }
    string s;
    cin>>s;
    s.push_back('L');
    sort(p, p+n, comp);
    int cu=p[0];
    cout<<cu+1<<" ";
    for(int a=0; a<n-1; a++)
    {
        vector <int> hull, hull2;
        for(int b=0; b<n; b++)
        {
            int i=p[b];
            if(us[i]==0)
            {
                while(hull.size()>1)
                {
                    int i2=hull.back(), i3=hull[hull.size()-2];
                    if(S(po[i3][0], po[i3][1], po[i2][0], po[i2][1], po[i][0], po[i][1])<0) hull.pop_back();
                    else break;
                }
                hull.push_back(i);

                while(hull2.size()>1)
                {
                    int i2=hull2.back(), i3=hull2[hull2.size()-2];
                    if(S(po[i3][0], po[i3][1], po[i2][0], po[i2][1], po[i][0], po[i][1])>0) hull2.pop_back();
                    else break;
                }
                hull2.push_back(i);
            }
        }


        if(hull2.size() and hull2.back()==hull.back()) hull2.pop_back();
        if(hull2.size() and hull2[0]==hull[0]) hull2.erase(hull2.begin());

        while(hull2.size())
        {
            hull.push_back(hull2.back());
            hull2.pop_back();
        }

        for(int b=0; b<hull.size(); b++)
        {
            int v=hull[b], ne=hull[(b+1)%hull.size()];
            r[v]=ne, l[ne]=v;
        }

        us[cu]=1;

        if(s[a]=='L') cu=l[cu];
        else cu=r[cu];

        cout<<cu+1<<" ";
    }

}