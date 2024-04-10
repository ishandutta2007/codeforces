#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP(X,Y) make_pair((X),(Y))
using namespace std;
const int SIZE = 100010;
char s[SIZE+5];
int nxt[SIZE],lat[SIZE];
bool pointed[SIZE];
int footprint_type(char c){return c=='R'?1:0;}
vector<int>seq[2][2];
vector<int>an[SIZE];
int pn;
void connect(int x,int y){
    nxt[x]=y;
    lat[y]=x;
}
bool check(vector<pair<int,int> >&seq){
    if(SZ(seq)<2)return 0;
    int st=seq.back().first,ed=seq.back().second,st2=seq[SZ(seq)-2].first,ed2=seq[SZ(seq)-2].second;
    if(s[ed]!=s[st2]){
        connect(ed,st2);
        seq.pop_back();
        seq.back()=MP(st,ed2);
        return 1;
    }
    if(s[ed2]!=s[st]){
        connect(ed2,st);
        seq.pop_back();
        seq.back()=MP(st2,ed);
        return 1;
    }
    if(s[st]!=s[ed]){
        if(ed<ed2){
            int z=lat[ed2];
            connect(ed,ed2);
            connect(ed2,st2);
            nxt[z]=0;
            seq.pop_back();
            seq.back()=MP(st,z);
        }
        else{
            int z=lat[ed];
            connect(ed2,ed);
            connect(ed,st);
            nxt[z]=0;
            seq.pop_back();
            seq.back()=MP(st2,z);
        }
        return 1;
    }
    return 0;
}
int main(){
    int m;
    scanf("%s",s+1);
    m=strlen(s+1);
    queue<int>qq[2];
    for(int i=1;i<=m;i++){
        int me=footprint_type(s[i]);
        if(SZ(qq[me^1])){
            connect(qq[me^1].front(),i);
            pointed[i]=1;
            qq[me^1].pop();
        }
        qq[me].push(i);
    }
    vector<pair<int,int> >seq;
    int cnt=-1;
    for(int i=1;i<=m;i++){
        if(!pointed[i]){
            cnt++;
            int ed=i;
            while(nxt[ed])ed=nxt[ed];
            seq.push_back(MP(i,ed));
            while(check(seq));
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<SZ(seq);i++){
        int now=seq[i].first;
        while(now){
            if(i||now!=seq[i].first)printf(" ");
            printf("%d",now);
            now=nxt[now];
        }
    }
    puts("");
    return 0;
}