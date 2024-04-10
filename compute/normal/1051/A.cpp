#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        string ss;
        cin>>ss;
        int low=0,up=0,digit=0;
        char pre=ss[0];
        for(int i=0;i<ss.length();i++)
        {
            
            if(ss[i]>='a'&&ss[i]<='z')
            {
                low++;
            }
            else if(ss[i]>='0'&&ss[i]<='9')
            {
                digit++;
            }
            else{
                up++;
            }
        }
        if(low==0&&digit!=0&&up!=0)
        {
            if(digit>=2)
            {
                for(int i=0;i<ss.length();i++)
                {
                    if(ss[i]>='0'&&ss[i]<='9') 
                    {
                        ss[i]='a';break;}
                }
            }
            else{
                for(int i=0;i<ss.length();i++)
                {
                    if(ss[i]>='A'&&ss[i]<='Z') {ss[i]='a';break;}}
            }
        }
        else if(digit==0&&low!=0&&up!=0)
        {
            if(low>=2)
                for(int i=0;i<ss.length();i++)
                {
                    if(ss[i]>='a'&&ss[i]<='z') 
                    {
                        ss[i]='0';
                        break;
                    }
                }
            else {
                for(int i=0;i<ss.length();i++)
                   { if(ss[i]>='A'&&ss[i]<='Z') {ss[i]='0';break;}}
            }
        }
        else if(up==0&&digit!=0&&low!=0)
        {
            if(digit>=2)
                for(int i=0;i<ss.length();i++)
                    {if(ss[i]>='0'&&ss[i]<='9') {ss[i]='A';break;}}
            else{
                for(int i=0;i<ss.length();i++)
                    {if(ss[i]>='a'&&ss[i]<='z') {ss[i]='A';break;}}
            }
        }
        else{
            if(up!=0&&low!=0&&digit!=0) pre='0';
            else if(up!=0){
                ss[0]='0';
                ss[1]='a';
            }
            else if(low!=0)
            {
                ss[0]='0';
                ss[1]='A';
            }
            else {
                ss[0]='A';
                ss[1]='a';
            }
        }
        cout<<ss<<endl;
    }
    return 0;
}