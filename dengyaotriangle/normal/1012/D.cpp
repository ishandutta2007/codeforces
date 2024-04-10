#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

vector<pair<int,int> >a;
bool iv=0,jv=0;
int main(){
    string s,t;
    cin>>s>>t;
    if(s[0]==t[0]&&s.back()!=t.back()){
        jv=1;
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
    }
    vector<int> p1,p2;
    p1.push_back(0);p2.push_back(0);
    for(int i=1;i<s.size();i++)if(s[i]!=s[i-1])p1.push_back(i);
    for(int i=1;i<t.size();i++)if(t[i]!=t[i-1])p2.push_back(i);
    p1.push_back(s.size());p2.push_back(t.size());
    for(int i=1;i<p1.size();i++){p1[i-1]=p1[i]-p1[i-1];}p1.pop_back();
    for(int i=1;i<p2.size();i++){p2[i-1]=p2[i]-p2[i-1];}p2.pop_back();
    int w0=INT_MAX,id=0,w1=max(p1.size(),p2.size())-1;
    if(p1.size()<p2.size())swap(p1,p2),iv=1;
    if(s[0]==t[0]){
        for(int i=1;i<=p1.size();i+=2){
            int h=max(p2.size()+i-1,p1.size()-i)-1+1;
            if(h<w0){
                id=i;w0=h;
            }
        }
        vector<int> x;
        int cnt=0;
        for(int i=0;i<id;i++)cnt+=p1[i],x.push_back(p1[i]);
        x.back()+=p2[0];
        for(int i=1;i<p2.size();i++)x.push_back(p2[i]);
        p1.erase(p1.begin(),p1.begin()+id);
        p2=x;
        a.push_back(make_pair(cnt,0));
    }else{
        for(int i=1;i<=p1.size();i+=2){
            int h=max(p2.size()+i-2,p1.size()-i)-1+1;
            if(h<w0){
                id=i;w0=h;
            }
        }
        if(w0<w1){
            vector<int> x;
            int cnt=0;
            for(int i=0;i<id;i++)x.push_back(p1[i]),cnt+=p1[i];
            if(p2.size()>1)x.back()+=p2[1];
            for(int i=2;i<p2.size();i++)x.push_back(p2[i]);
            p1.erase(p1.begin(),p1.begin()+id);
            p1[0]+=p2[0];int c2=p2[0];
            p2=x;
            a.push_back(make_pair(cnt,c2));
        }
    }
    int sp1=0,sp2=0;
    for(int i=0;i<max(p1.size(),p2.size())-1;i++){
        if(i>=p1.size()){
            int r=p2[i];
            a.push_back(make_pair(sp1,sp2+r));sp2+=r;
        }else if(i>=p2.size()){
            int l=p1[i];
            a.push_back(make_pair(sp1+l,sp2));sp1+=l;
        }else{
            int l=p1[i],r=p2[i];
            a.push_back(make_pair(sp1+l,sp2+r));sp2+=r;sp1+=l;
        }
        swap(sp1,sp2);
    }
    cout<<a.size()<<endl;
    int pa=s.size(),pb=t.size();
    bool k=0;
    for(int i=0;i<a.size();i++){
        if(iv)swap(a[i].first,a[i].second);
        if(jv){
            int k0=a[i].first,k1=a[i].second;
            if(k)cout<<pb-a[i].second<<' '<<pa-a[i].first<<'\n';
            else cout<<pa-a[i].first<<' '<<pb-a[i].second<<'\n';
            pa=pa-k0+k1;
            pb=pb-k1+k0;
            k^=1;
        }else{
            cout<<a[i].first<<' '<<a[i].second<<'\n';
        }
    }
    return 0;
}