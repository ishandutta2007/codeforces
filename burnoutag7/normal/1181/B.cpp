#include<bits/stdc++.h>
using namespace std;

int n;
string s;
string f,b;

string mns(string a,string b);

string func(){
    string res;
    string mn=mns(f,b);
    string mx=(mn==f)?b:f;
    res=mx;
    int cur=0;
    for(int i=1;i<=mn.size();i++){
        cur+=mn[mn.size()-i]-'0'+res[res.size()-i]-'0';
        res[res.size()-i]=cur%10+'0';
        cur/=10;//cout<<res<<endl;
    }
    for(int i=mn.size()+1;i<=res.size();i++){
        cur+=res[res.size()-i]-'0';
        res[res.size()-i]=cur%10+'0';
        cur/=10;//cout<<res<<endl;
    }
    if(cur>0){
        res=char(cur+'0')+res;
    }
    return res;
}

string mns(string a,string b){
    if(a.size()!=b.size())
        if(a.size()<b.size())
            return a;
        else
            return b;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
            if(a[i]<b[i])
                return a;
            else
                return b;
    return a;
}

string ans;

void upd(){
    string tmp=func();
    if(tmp==""){
        return;
    }
    ans=mns(ans,tmp);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>s;
    for(int i=0;i<100050;i++)ans+='9';
    for(int i=(n+1)/2-1;i>=0;i--){
        if(s[i]!='0'){//cout<<i<<endl;
            f=s.substr(0,i);
            b=s.substr(i,s.size()-i);//cout<<f<<endl<<b<<endl;
            upd();
            break;
        }
    }
    for(int i=(n+1)/2;i<(n+1)/2+1;i++){
        if(s[i]!='0'){//cout<<i<<endl;
            f=s.substr(0,i);
            b=s.substr(i,s.size()-i);//cout<<f<<endl<<b<<endl;
            upd();
        }
    }
    for(int i=(n+1)/2+1;i<n;i++){
        if(s[i]!='0'){//cout<<i<<endl;
            f=s.substr(0,i);
            b=s.substr(i,s.size()-i);//cout<<f<<endl<<b<<endl;
            upd();
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}