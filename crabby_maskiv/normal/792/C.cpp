#include<iostream>
#include<cstring>
using namespace std;
string s;
string s1;
int step1,step2;
bool flag=false;
int main()
{
    cin>>s;
    s1=s;
    int N=s.length();
    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=s[i]-'0';
    }
    int yu=sum%3;
    int sum1=sum;
    int sum2=sum;
    if(yu!=0)
    {
        for(int i=N-1;i>=0;i--)
        {
            if((s[i]-'0')%3==yu)
            {
                sum1-=s[i]-'0';
                s.erase(i,1);
                flag=true;
                step1++;
                break;
            }
        }
    }
    else
    {
        flag=true;
    }
    N=s.length();
    if(flag)
    {
        int cnt=0;
        if(N!=1)
        {
            while(cnt<N-1&&s[0]=='0')
            {
                s.erase(0,1);
                cnt++;
            }
            if(cnt!=N-1)
            {
                step1+=cnt;
            }           
        }
        if(N==0)
        {
            step1=-1;
        }
    }
    else
    {
        step1=-1;
    }

    if(yu==1)
    {
        yu=2;
    }
    else if(yu==2)
    {
        yu=1;
    }
    int tmp=0;
    for(int i=N-1;i>=0;i--)
    {
        if(yu==(s1[i]-'0')%3)
        {
            sum2-=s1[i]-'0';
            s1.erase(i,1);
            tmp++;
        }
        if(tmp>=2)
        {
            step2+=2;
            break;
        }
    }
    if(tmp<2)
    {
        step2=-1;
    }
    N=s1.length();
    int cnt=0;
    if(N!=1)
    {
        while(cnt<N-1&&s1[0]=='0')
        {
            s1.erase(0,1);
            cnt++;
        }
        if(cnt!=N-1)
        {
            step2+=cnt;
        }
    }
    if(tmp<2||N==0)
    {
        step2=-1;
    }
    if(step1<=step2&&(step1!=-1&&step2!=-1))
    {
        cout<<s<<endl;
    }
    else if(step1>step2&&(step1!=-1&&step2!=-1))
    {
        cout<<s1<<endl;
    }
    else if(step1!=-1&&step2==-1)
    {
        cout<<s<<endl;
    }
    else if(step1==-1&&step2!=-1)
    {
        cout<<s1<<endl;
    }
    else if(step1==-1&&step2==-1)
    {
        cout<<-1<<endl;
    }
    return 0;
 }