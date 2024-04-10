#include <bits/stdc++.h>

using namespace std;

int r1,c1;
int r2,c2;

string a;

bool atac_cal(int r,int c,int r2,int c2)
{
    int dr=abs(r-r2);
    int dc=abs(c-c2);
    if(dr+dc==3 && (dr==2 || dc==2))
        return 1;
    return 0;
}

bool atac_tura(int r,int c,int r2,int c2)
{
    if(r==r2)
        return 1;
    if(c==c2)
        return 1;
    return 0;
}

int cnt=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    r1=a[0]-'a'+1;   c1=a[1]-'0';
    cin>>a;
    r2=a[0]-'a'+1;   c2=a[1]-'0';
    for(int r3=1;r3<=8;r3++)
    {
        for(int c3=1;c3<=8;c3++)
        {
            if(atac_cal(r3,c3,r2,c2)==1)continue;
            if(atac_cal(r3,c3,r1,c1)==1)continue;
            if(atac_tura(r1,c1,r3,c3)==1)continue;
            cnt++;
        }
    }
    cnt--;
    cout<<cnt<<"\n";
    return 0;
}
/**

**/