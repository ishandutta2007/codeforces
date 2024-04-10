#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void error()
{
        cout<<":(";
        exit(0);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        string s;
        cin>>s;
        int top=0;
        int lft=0;
        for(auto &ch:s)
        {
                if(ch=='(')
                {
                        top++;
                }
                if(ch==')')
                {
                        top--;
                }
                if(ch=='?')
                {
                        lft++;
                }
        }
        int open=0;
        int close=0;
        int val=lft-top;
        if(val%2==1)
        {
                error();
        }
        open=val/2;
        close=lft-open;
        if(0<=open && open<=lft && 0<=close && close<=lft)
        {
                string a;
                top=0;
                int cnt0=0;
                for(auto &ch:s)
                {
                        if(ch=='(')
                        {
                                a+=ch;
                                top++;
                        }
                        if(ch==')')
                        {
                                a+=ch;
                                top--;
                        }
                        if(ch=='?')
                        {
                                if(open>0)
                                {
                                        top++;
                                        open--;
                                        a+="(";
                                }
                                else
                                {
                                        if(close==0)
                                        {
                                                error();
                                        }
                                        close--;
                                        top--;
                                        a+=")";
                                }
                        }
                        if(top<0)
                        {
                                error();
                        }
                        if(top==0)
                        {
                                cnt0++;
                        }
                }
                if(top!=0 || cnt0!=1)
                {
                       error();
                }
                cout<<a<<"\n";
                return 0;
        }
        else
        {
                error();
        }
        return 0;
}
/**

**/