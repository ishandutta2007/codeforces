#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
vector<pair<int,int> >now,an;
set<pair<int,int> >r;
int main(){
    int i,j,k,n,s,error=0;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        r.insert(make_pair(k,i));
    }
    while(!r.empty()){
        set<pair<int,int> >::iterator it=r.end();
        it--;
        pair<int,int>tmp=*it;
        now.clear();
        while(tmp.first){
            if(it==r.begin())break;
            it--;
            if(it->first==0)break;
            now.pb(make_pair(it->first-1,it->second));
            an.pb(make_pair(it->second,tmp.second));
            tmp.first--;
        }
        if(tmp.first){
            error=1;
            break;
        }
        r.erase(it,r.end());
        r.insert(now.begin(),now.end());
    }
    if(error)cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl<<an.size()<<endl;
        for(i=0;i<an.size();i++)printf("%d %d\n",an[i].first+1,an[i].second+1);
    }
    return 0;
}