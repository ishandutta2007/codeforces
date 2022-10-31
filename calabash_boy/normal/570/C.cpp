#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX 600050
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
char str[MAX];
struct T{
    int l,r,v;
}t[MAX << 2];
inline int lchild(int x) {return (x << 1);}
inline int rchild(int x) {return (x << 1) + 1;}
inline int fa(int x) {return (x >> 1);}
int aa(char c) {return (c == '.') ? 1 : 0;}
void build(int x,int l,int r) {
    int m = (l + r) / 2;
    t[x].l = l;t[x].r = r;t[x].v = 0;
    if(l == r) return ;
    build(lchild(x),l,m);
    build(rchild(x),m+1,r);
}
void ins(int x,int l,int r,int pos,int v) {
    int m = (l + r) / 2;
    if(l == r) {
        t[x].v = v;
        //printf("%d %d\n",x,t[x].v);
        return;
    }
    else {
        if(pos <= m)
            ins(lchild(x),l,m,pos,v);
        else if(pos > m)
            ins(rchild(x),m+1,r,pos,v);
        t[x].v = t[lchild(x)].v + t[rchild(x)].v;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    //while(cin >> n >> m) {
    cin >> n >> m;
        scanf("%s",str);
        //puts(str);
        if(n == 1) {
            for(int i = 1;i <= m;i++) {
                char ss[2];
                int x;
                scanf("%d%s",&x,ss);
                printf("0\n");
            }
            return 0;
            //continue;
        }
        build(1,1,n-1);
        int l = aa(str[0]);
        //printf("%d\n",l);
        for(int i = 1;i < n;i++) {
            ins(1,1,n-1,i,l&aa(str[i]));
            l = aa(str[i]);
           // printf("%d\n",l);
        }
        for(int i = 1;i <= m;i++) {
            int x;scanf("%d",&x);
            char ss[2];
            scanf("%s",ss);
            if(x != 1) ins(1,1,n-1,x-1,aa(ss[0])&aa(str[x-2]));
            if(x != n) ins(1,1,n-1,x,aa(ss[0])&aa(str[x]));
            str[x-1] = ss[0];
            printf("%d\n",t[1].v);
        }
//    }
    return 0;
}