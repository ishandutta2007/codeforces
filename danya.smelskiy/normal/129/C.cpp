#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define el "\n"
using namespace std;

void file()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
}

int n,kkk;

string a[101],b[101];
bool f;
bool g;
void rec(int x,int y,int hod)
{
    //cout<<x<<" "<<y<<" "<<a[x-hod+1][y-1]<<" "<<hod<<el;
    //kkk++;
    if(x<1||y<1||x>8||y>8||f)return;
    if(x-hod+1>=1&&a[x-hod+1][y-1]=='S')return;
    if(x-hod>=1&&a[x-hod][y-1]=='S')return;
    int kol=0;
    for(int i=8;i>=1;--i)
    {
        for(int j=1;j<=8;++j)
        {
            //cout<<i<<" "<<j<<el;
            if(a[i][j-1]=='S')
            {
                if(i+hod<=8)
                kol++;
                //kkk++;
            }
        }
    }
    //cout<<kol;
    //if(kkk>=100000000)g=true;
    if(f||g)return;
    if(kol==0)f=true;
    rec(x-1,y-1,hod+1);
    if(f||g)return;
    rec(x-1,y,hod+1);
    if(f||g)return;
    rec(x-1,y+1,hod+1);
    if(f||g)return;
    rec(x,y-1,hod+1);
    if(f||g)return;
    rec(x,y,hod+1);
    if(f||g)return;
    rec(x,y+1,hod+1);
    if(f||g)return;
    rec(x+1,y-1,hod+1);
    if(f||g)return;
    rec(x+1,y,hod+1);
    if(f||g)return;
    rec(x+1,y+1,hod+1);
}

int main()
{
    //bs;
    //file();
    for(int i=1;i<=8;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    rec(8,1,0);

    if(f)cout<<"WIN";
    else cout<<"LOSE";
}