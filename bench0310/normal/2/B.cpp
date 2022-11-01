#include <iostream>

using namespace std;

bool inRange(int x,int y,int n);

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n][n];
    int s2[n][n];
    int s5[n][n];
    int cs2[n][n];
    int cs5[n][n];
    int p2[n][n];
    int p5[n][n];
    bool zero=0;
    int x;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<n;i++)
        {
            cin >> arr[o][i];
            int temp=arr[o][i];
            s2[o][i]=0;
            s5[o][i]=0;
            cs2[o][i]=1000000;
            cs5[o][i]=1000000;
            if(temp==0)
            {
                zero=1;
                x=i;
                s2[o][i]=1000;
                s5[o][i]=1000;
                continue;
            }
            while(temp%2==0)
            {
                s2[o][i]++;
                temp/=2;
            }
            while(temp%5==0)
            {
                s5[o][i]++;
                temp/=5;
            }
        }
    }
    cs2[n-1][n-1]=s2[n-1][n-1];
    cs5[n-1][n-1]=s5[n-1][n-1];
    p2[n-1][n-1]=2;
    p5[n-1][n-1]=2;
    for(int o=n-1;o>=0;o--)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(inRange(o+1,i,n))
            {
                if(arr[o+1][i]==0) continue;
                if(cs2[o+1][i]+s2[o][i]<cs2[o][i])
                {
                    cs2[o][i]=cs2[o+1][i]+s2[o][i];
                    p2[o][i]=0;
                }
                if(cs5[o+1][i]+s5[o][i]<cs5[o][i])
                {
                    cs5[o][i]=cs5[o+1][i]+s5[o][i];
                    p5[o][i]=0;
                }
            }
            if(inRange(o,i+1,n))
            {
                if(arr[o][i+1]==0) continue;
                if(cs2[o][i+1]+s2[o][i]<cs2[o][i])
                {
                    cs2[o][i]=cs2[o][i+1]+s2[o][i];
                    p2[o][i]=1;
                }
                if(cs5[o][i+1]+s5[o][i]<cs5[o][i])
                {
                    cs5[o][i]=cs5[o][i+1]+s5[o][i];
                    p5[o][i]=1;
                }
            }
        }
    }
    if(zero&&(1<min(cs2[0][0],cs5[0][0])))
    {
        cout << 1 << endl;
        int o=0,i=0;
        while(i<x)
        {
            cout << "R";
            i++;
        }
        while(o<n-1)
        {
            cout << "D";
            o++;
        }
        while(i<n-1)
        {
            cout << "R";
            i++;
        }
    }
    else
    {
        if(cs2[0][0]<=cs5[0][0])
        {
            cout << cs2[0][0] << endl;
            int o=0,i=0;
            while(p2[o][i]!=2)
            {
                if(p2[o][i]==0)
                {
                    cout << "D";
                    o++;
                }
                else
                {
                    cout << "R";
                    i++;
                }
            }
            cout << endl;
        }
        else
        {
            cout << cs5[0][0] << endl;
            int o=0,i=0;
            while(p5[o][i]!=2)
            {
                if(p5[o][i]==0)
                {
                    cout << "D";
                    o++;
                }
                else
                {
                    cout << "R";
                    i++;
                }
            }
            cout << endl;
        }
    }
    return 0;
}

bool inRange(int x,int y,int n)
{
    if(x<0||y<0||x>=n||y>=n) return 0;
    else return 1;
}