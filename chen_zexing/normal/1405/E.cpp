#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 3;
int n , q , a[MAXN] , f[MAXN];
struct node{
    int l , r , num ;
}tre[MAXN<<2];
inline void build( int i , int l , int r ){
    tre[i].l = l , tre[i].r = r , tre[i].num = 0;
    if( l == r ) return ;
    int mid = ( l +r ) >> 1;
    build( i << 1 , l , mid );
    build( i << 1 | 1 , mid + 1 , r );
}
inline int query( int i , int s ){
    if( tre[i].l == tre[i].r ){
        return tre[i].l - 1;
    }
    if( s > tre[i<<1].num ){
        s -= tre[i<<1].num;
        return query( i << 1 | 1 , s );
    }
    else
        return query( i << 1 , s );
}
inline void modify( int i , int l , int r ){
    if( tre[i].l > r || tre[i].r < l ) return ;
    if( tre[i].l == l && tre[i].r == r ){
        tre[i].num ++;
        return ;
    }
    modify( i << 1 , l , r );
    modify( i << 1 | 1 , l , r );
    tre[i].num = tre[i<<1].num + tre[i<<1|1].num;
}
struct edge{
    int xs , xe , y , num;
    int t;
    friend bool operator < ( edge a , edge b ){
        if( a.y != b.y ) return a.y < b.y;
        return a.t < b.t;
    }
}s[MAXN<<1];
int ncnt , ans[MAXN] , sum[MAXN];
int lowbit( int x ){ return x & -x;}
void change( int x , int delta ){
    for( ; x <=n ; x += lowbit( x ) ) sum[x] += delta;
}
int query1( int l  , int r ){
    int tot = 0;
    l --;
    for( ; r ; r -= lowbit( r ) )
        tot += sum[r];
    for( ;  l ; l -= lowbit( l ) )
        tot -= sum[l];
    return tot;
}
int main(){
    scanf( "%d%d" , &n , &q );
    build( 1 , 0 , n + 1 );
    for( int i = 1 ; i <= n ; i ++ ){
        scanf( "%d" , &a[i] );
        if( a[i] == i ) f[i] = i -1;
        if( a[i] > i ) f[i] = -1;
        if( a[i] < i )
            f[i] = query( 1 , tre[1].num - i + a[i] + 1 );
        modify( 1 , f[i] + 1 , f[i] + 1 );
    }
    for( int i = 1 ; i <= n ; i += 1 ){
        s[++ncnt].t = 1 , s[ncnt].xs = s[ncnt].xe = i , s[ncnt].y = f[i];
    }
    for( int i = 1 ; i <= q ; i ++ ){
        int x , y;scanf( "%d%d" , &x , &y );
        y = n - y;x ++;
        s[++ncnt].t = 2 ;s[ncnt].xs = x , s[ncnt].xe = y , s[ncnt].y = n + 3 , s[ncnt].num = i;
        s[++ncnt].t = 0 ;s[ncnt].xs = x , s[ncnt].xe = y , s[ncnt].y = x - 1 , s[ncnt].num = i;
    }
    sort( s + 1 , s + ncnt + 1) ;
    for( int i = 1 ; i <= ncnt ; i ++ ){
        if( s[i].t == 1 ){
            if( s[i].y == -1 ) continue;
            change( s[i].xe , 1 );
        }
        else if( s[i].t == 2 ){
            int tot = query1( s[i].xs , s[i].xe );
            ans[s[i].num] = tot - ans[s[i].num];
        }
        else{
            int tot = query1( s[i].xs , s[i].xe );
            ans[s[i].num] = tot;
        }
    }
    for( int i = 1 ; i <= q ; i ++ )
        printf( "%d\n" , ans[i] );
    return 0;
}