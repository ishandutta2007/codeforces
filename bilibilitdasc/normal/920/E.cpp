#import<bits/stdc++.h>
#define I int
#define Y(c)for(I i=0;i<c;++i)
#define y(c)for(I i=1;i<=c;++i)
#define A 1505
#define f(x)if(!q[x[i]])x[i]=V;x[i]=upper_bound(_,_+c,x[i])-_;
using namespace std;I n,m,d[A*A],u[A*A],v[A*A],q[A*A],p[A],s[A],S[A],D[A][A],V,T,R,_[A],a[A],c,Q;I G(I x){return (p[x]==x)?x:(p[x]=G(p[x]));}void C(I x,I y){x=G(x);y=G(y);if(x^y)p[x]=y,s[y]+=s[x];}main(){cin>>n>>m;*d=A;Y(m){cin>>u[i]>>v[i];++d[u[i]];++d[v[i]];}y(n)if(d[i]<d[V])V=i;Y(m)if(u[i]==V||i[v]==V)q[u[i]]=q[i[v]]=1;q[V]=1;y(n){if(i[q]){_[c++]=i;p[c]=c;s[c]=S[c]=1;}if(i==V)R=c;else if(!i[q])++T;}s[R]+=T;R[S]+=T;Y(m){f(u)f(v)D[u[i]][v[i]]=++D[v[i]][u[i]];}y(c)for(I j=1;j<i;++j)if(j[i[D]]<S[i]*S[j])C(i,j);y(c)if(p[i]==i)a[Q++]=s[i];sort(a,a+Q);cout<<Q<<endl;Y(Q)cout<<a[i]<<' ';}