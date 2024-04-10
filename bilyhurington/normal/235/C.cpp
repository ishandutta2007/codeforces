/*
 * @Author: BilyHurington
 * @Date: 2020-08-03 21:51:22
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-06 21:31:35
 */
#include<bits/stdc++.h>
using namespace std;
namespace Suffix_Automation{
    int ch[2000010][26],len[2000010],fail[2000010],cnt[2000010],node_tot,last_node;
    int tag[2000010];
	void Init(){node_tot=last_node=1;}
	void Insert(int x){
		int p=last_node,now=++node_tot;
		len[now]=len[p]+1;last_node=now;cnt[now]=1;
		for(;p&&!ch[p][x];p=fail[p]) ch[p][x]=node_tot;
		if(!p){fail[now]=1;return;}
		int noww=ch[p][x];
		if(len[noww]==len[p]+1){fail[now]=noww;return;}
		int clone_noww=++node_tot;
		memcpy(ch[clone_noww],ch[noww],sizeof(ch[noww]));
		len[clone_noww]=len[p]+1;
		fail[clone_noww]=fail[noww];
		for(;p&&ch[p][x]==noww;p=fail[p]) ch[p][x]=clone_noww;
		fail[now]=fail[noww]=clone_noww;
	}
    vector<int> T[2000010];
    void dfs(int x){
        for(int i=0;i<T[x].size();i++){
            dfs(T[x][i]);
            cnt[x]+=cnt[T[x][i]];
        }
    }
    void Build(){
        for(int i=2;i<=node_tot;i++) T[fail[i]].push_back(i);
        // for(int i=1;i<=node_tot;i++) printf("%d ",fail[i]-1);printf("\n");
        dfs(1);
        // for(int i=1;i<=node_tot;i++) printf("%d ",cnt[i]);printf("\n");
    }
    int Node,Len,M,ID;
    void Clear(int m,int id){M=m;ID=id;Node=1;Len=0;}
    void Add_Back(int x){
        while(Node>1&&!ch[Node][x]) Node=fail[Node],Len=len[Node];
        if(ch[Node][x]) Node=ch[Node][x],Len++;
        // printf("%d %d\n",Node,Len);
    }
    void Del_Front(){
        if(Len<=M) return;
        Len--;
        if(Len==len[fail[Node]]) Node=fail[Node];
        // printf("%d %d\n",Node,Len);
    }
    int Ask(){
        // printf("%d %d %d %d\n",Len,M,tag[Node],ID);
        if(Len==M&&tag[Node]!=ID){tag[Node]=ID;return cnt[Node];}
        return 0;
    }
}
using namespace Suffix_Automation;
int n,q;char s[1000010];
int main(){
    scanf("%s",s+1);Init();
    n=strlen(s+1);
    for(int i=1;i<=n;i++) Insert(s[i]-'a');
    Build();scanf("%d",&q);
    while(q--){
        scanf("%s",s+1);n=strlen(s+1);Clear(n,q+1);
        for(int i=1;i<=n;i++) Add_Back(s[i]-'a');
        long long ans=0;
        for(int i=1;i<=n;i++){
            Add_Back(s[i]-'a');
            Del_Front();
            ans+=Ask();
        }
        printf("%lld\n",ans);
    }
    return 0;
}