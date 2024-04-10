#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

string name[4];
int gp[4],gm[4],s[4],p[4];
int c = 0;

int id(const string & a)
{
    int f = -1;
    for (int i=0;i<c;i++)
        if (name[i]==a)
        {
                       f = i;
                       break;
        }
    if (f==-1)
    {
              f = c;
              c++;
              gp[f]=0;
              gm[f]=0;
              s[f]=0;
              p[f]=0;
              name[f]=a;
    }
    return f;
}

void add(int i1, int i2, int x, int y)
{
     p[i1]++;
     p[i2]++;
     gp[i1] += x;
     gp[i2] += y;
     gm[i1] += y;
     gm[i2] += x;
     if (x>y)
             s[i1] += 3;
     else
     if (x==y)
     {
              s[i1] += 1;
              s[i2] += 1;
     }
     else
         s[i2] += 3;
}

void msort(int s[],int gp[],int gm[],string name[])
{
     for (int i=0;i<4;i++)
        for (int j=i+1;j<4;j++)
            if (s[j]<s[i] ||
                (s[j]==s[i] && gp[j]-gm[j]<gp[i]-gm[i]) ||
                (s[j]==s[i] && gp[j]-gm[j]==gp[i]-gm[i] && gp[j]<gp[i])||
                (s[j]==s[i] && gp[j]-gm[j]==gp[i]-gm[i] && gp[j]==gp[i] && name[j]>name[i]))
                {
                            int buf = gp[i];gp[i]=gp[j];gp[j]=buf;
                            buf = gm[i];gm[i]=gm[j];gm[j]=buf;
                            buf = s[i];s[i]=s[j];s[j]=buf;
                            string a = name[i];
                            name[i]=name[j];
                            name[j]=a;
                }
}

bool check(int i1, int i2, int x, int y)
{
     int ts[4],tgp[4],tgm[4];
     string tname[4];
     for (int i=0;i<4;i++)
     {
         ts[i] = s[i];
         tgp[i]= gp[i];
         tgm[i] =gm[i];
         tname[i] = name[i];
     }
     ts[i1] += 3;
     tgp[i1] += x;
     tgm[i1] += y;
     tgp[i2] += y;
     tgm[i2] += x;
     msort(ts,tgp,tgm,tname);
     return (tname[3]=="BERLAND" || tname[2]=="BERLAND");
}
    
int main(){
    for (int i=0;i<5;i++)
    {
        string a,b;
        int x,y;
        char t;
        cin >> a >> b >> x >> t >> y;
        add(id(a),id(b),x,y);
    }
    int x,y;
    for (int i=0;i<4;i++)
        if (name[i]=="BERLAND")
        {
                               x = i;
                               break;
        }
    for (int i=0;i<4;i++)
        if (p[i]==2 && i!=x)
        {
                    y = i;
                    break;
        }
    int r1=-1,r2;
    for (int i=1;i<=50;i++)
        for (int j=0;j<i;j++)
            if (check(x,y,i,j))
               if (r1==-1 || (r1!=-1 && i-j<r1-r2) || (r1!=-1 && i-j==r1-r2 && j<r2))
               {
                          r1 = i;
                          r2 = j;
               }
    if (r1==-1)
       cout << "IMPOSSIBLE";
    else
        cout << r1 << ":" << r2;
    return 0;
}