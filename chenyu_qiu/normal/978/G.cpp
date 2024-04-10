#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2*1e5+10;
struct node {
    int id;
    int s,d,c;
    bool operator <(const node &u)const{
        return d>u.d;
    }
};
int days[100+10];
vector<node> s[100+10];
priority_queue<node> q; 
int main(){
    int n,m;
    node exam;
    cin>>n>>m;
    memset(days,-1,sizeof(days));
    for(int i=0;i<m;i++){
        cin>>exam.s>>exam.d>>exam.c;
        exam.id = i+1;
        s[exam.s].push_back(exam);//i
        days[exam.d] = m+1;//
    }
    int flag = 0;
    for(int i=1;i<=n;i++){
        int len = s[i].size();
        if(len>0) {
            for(int j=0;j<len;j++) q.push(s[i][j]);
        } 
        if(days[i]==m+1) continue;
        if(q.size()==0) {
            days[i]=0;continue;
        } //rest
        node tmp = q.top();q.pop();
        if(tmp.d<i) { 
            flag=1;break;
        }
        days[i] = tmp.id;
        tmp.c -= 1;
        if(tmp.c>0) q.push(tmp); 
    }   
    if(q.size()!=0) flag=1;    
    if(flag) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++) cout<<days[i]<<" ";
        cout<<endl;
    }
}