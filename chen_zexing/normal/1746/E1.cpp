#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int cnt;
int query(vector <int> v){
    ++cnt;
    printf("? %d ",int(v.size()));
    for(int i=0;i<v.size();i++) printf("%d%c",v[i],i+1==v.size()?'\n':' ');
    fflush(stdout);
    char s[5];
    scanf("%s",s+1);
    return s[1]=='Y';
}
vector <int> merge(vector <int> a,vector <int> b){
    vector <int> ans;
    for(auto t:a) ans.push_back(t);
    for(auto t:b) ans.push_back(t);
    return ans;
}
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) v.push_back(i);
        while(v.size()>2){
            //cout<<"???"<<v.size()<<endl;
            int p1=v.size()/3,p2=(v.size()-p1)/2+p1;
            vector <int> t1,t2,t3;
            for(int i=0;i<p1;i++) t1.push_back(v[i]);
            for(int i=p1;i<p2;i++) t2.push_back(v[i]);
            for(int i=p2;i<v.size();i++) t3.push_back(v[i]);
            int r1=query(t1);
            if(r1){
                int r2=query(t2);
                if(r2) v=merge(t1,t2);
                else v=merge(t1,t3);
            }
            else{
                int r2=query(t1);
                if(!r2) v=merge(t2,t3);
                else{
                    int r3=query(t2);
                    if(r3) v=merge(t1,t2);
                    else v=merge(t1,t3);
                }
            }
        }
        printf("! %d\n",v[0]);
        fflush(stdout);
        char s[5];
        scanf("%s",s+1);
        if(s[2]==')') exit(0);
        else printf("! %d\n",v[1]);
    }
    return 0;
}