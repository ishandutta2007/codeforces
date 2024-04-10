#include <stdio.h>
#include <algorithm>
#define MAXN 11000

using namespace std;

const int inf=1000000;

int sn;
int s[MAXN];
int next[MAXN]={0};
bool _islucky[MAXN]={0};

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }
inline void gen() {
   sn=0;
   s[sn++]=4;
   s[sn++]=7;
   for(int t=1;t<7;t++) {
      int tn=sn;
      for(int i=0;i<tn;i++) {
         s[sn++]=s[i]*10+4;
         s[sn++]=s[i]*10+7;
      }
   }
   sort(s,s+sn);
   next[0]=4;
   for(int i=0;i<sn&&s[i]<MAXN;i++) {
      next[s[i]]=s[i+1];
      _islucky[s[i]]=1;
   }
   for(int i=1;i<MAXN;i++)
      next[i]=max(next[i-1],next[i]);
}
inline bool islucky(int x) {
   return x<MAXN&&_islucky[x];
}

class Node {
   public:
      int vl,vr,add,madd,luck;
      Node *_l,*_r;
      Node(int li,int ri):vl(li),vr(ri) {
         _l=_r=NULL;
         add=0;
         madd=next[0];
         luck=0;
      }
      ~Node() {
         if(_l) delete _l;
         if(_r) delete _r;
      }
      Node* left() {
         if(!_l) {
            int m=(vl+vr)>>1;
            _l=new Node(vl,m);
         }
         return _l;
      }
      Node* right() {
         if(!_r) {
            int m=(vl+vr)>>1;
            _r=new Node(m+1,vr);
         }
         return _r;
      }
      void up() {
         luck=left()->luck+right()->luck;
         madd=min(left()->madd,right()->madd);
      }
      void down() {
         left()->add+=add;
         right()->add+=add;
         left()->madd-=add;
         right()->madd-=add;
         add=0;
      }
      void addf(int l,int r,int a) {
         int m=(vl+vr)>>1;
         //printf("%d %d %d\n",l,r,a);
         if(vl==vr) {
            add+=a;
            luck=islucky(add);
            //printf("%d: %d\n",add,luck);
            if(luck) madd=1;
            else madd=next[add]-add;
         } else {
            if(add) down();
            if(vl==l&&vr==r) {
               if(madd<=a) {
                  left()->addf(l,m,a);
                  right()->addf(m+1,r,a);
                  up();
               } else {
                  add+=a;
                  madd-=a;
               }
            } else {
               down();
               if(r<=m) left()->addf(l,r,a);
               else if(l>m) right()->addf(l,r,a);
               else {
                  left()->addf(l,m,a);
                  right()->addf(m+1,r,a);
               }
               up();
            }
         }
      }
      int get(int l,int r) {
         int m=(vl+vr)>>1;
         if(vl==l&&vr==r) {
            return luck;
         } else {
            if(r<=m) return left()->get(l,r);
            else if(l>m) return right()->get(l,r);
            else return left()->get(l,m)+right()->get(m+1,r);
         }
      }
};

int main(void)
{
   int n,q;
   gen();
   scanf("%d %d",&n,&q);
   Node seg(0,n);
   for(int i=1;i<=n;i++) {
      int x;
      scanf("%d",&x);
      seg.addf(i,i,x);
   }
   char str[20];
   while(q--) {
      int l,r,a;
      scanf("%s",str);
      if(str[0]=='c') {
         scanf("%d %d",&l,&r);
         printf("%d\n",seg.get(l,r));
      } else {
         scanf("%d %d %d",&l,&r,&a);
         seg.addf(l,r,a);
      }
   }
   return 0;
}