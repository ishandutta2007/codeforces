#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;
struct data{
    int win,x,y;
    bool operator<(data b)const{
        if(win<b.win)return 1;
        if(win>b.win)return 0;
        return x<b.x||(x==b.x&&y>b.y);
    }
}answer;
string dic[32];
map<string,long long>word[32];
map<string,data>dp[32];
int count_one(long long x){
    int an=0;
    while(x){
        an++;
        x-=x&-x;
    }
    return an;
}
main(){
    int n,i,j,k,ma,sum;
    cin>>n;
    for(i=0;i<n;i++)cin>>dic[i];
    for(i=0;i<n;i++){
        for(j=0;j<dic[i].size();j++){
            ma=sum=0;
            for(k=1;j+k<=dic[i].size();k++){
                sum+=dic[i][j+k-1]-'a'+1;
                ma=max(ma,dic[i][j+k-1]-'a'+1);
                word[k][dic[i].substr(j,k)]|=sum*ma;
                word[k][dic[i].substr(j,k)]|=1ll<<(i+32);
            }
        }
    }
    map<string,long long>::iterator it;
    for(i=1;i<=30;i++){
        for(it=word[i].begin();it!=word[i].end();it++)it->second=((it->second)&((1<<30)-1))+count_one((it->second)>>30);
    }
    answer=(data){0,-1,1000000000};
    for(i=30;i>0;i--){
        for(it=word[i].begin();it!=word[i].end();it++){
            if(!dp[i].count(it->first))dp[i][it->first]=(data){0,0,0};
            data tmp=dp[i][it->first];
            if(i==1){
                if(answer<(data){tmp.win^1,tmp.y+it->second,tmp.x})answer=(data){tmp.win^1,tmp.y+it->second,tmp.x};
            }
            else{
                if(!dp[i-1].count((it->first).substr(1,i-1))||dp[i-1][(it->first).substr(1,i-1)]<(data){tmp.win^1,tmp.y+it->second,tmp.x})
                    dp[i-1][(it->first).substr(1,i-1)]=(data){tmp.win^1,tmp.y+it->second,tmp.x};
                if(!dp[i-1].count((it->first).substr(0,i-1))||dp[i-1][(it->first).substr(0,i-1)]<(data){tmp.win^1,tmp.y+it->second,tmp.x})
                    dp[i-1][(it->first).substr(0,i-1)]=(data){tmp.win^1,tmp.y+it->second,tmp.x};
            }
        }
    }
    if(answer.win)cout<<"First\n";
    else cout<<"Second\n";
    cout<<answer.x<<" "<<answer.y<<endl;
}