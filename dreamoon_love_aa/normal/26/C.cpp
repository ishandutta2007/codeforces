#include<stdio.h>
char s[128][128];
void fill(int x,int y,int dx,int dy){
    int i,j,k;
    bool used[26];
    for(i=0;i<26;i++)used[i]=0;
    for(i=0;i<dx;i++){
        if(y&&s[x+i][y-1])used[s[x+i][y-1]-'a']=1;
        if(s[x+i][y+dy])used[s[x+i][y+dy]-'a']=1;
    }
    for(i=0;i<dy;i++){
        if(x&&s[x-1][y+i])used[s[x-1][y+i]-'a']=1;
        if(s[x+dx][y+i])used[s[x+dx][y+i]-'a']=1;
    }
    for(i=0;used[i];i++);
    for(j=0;j<dx;j++)
        for(k=0;k<dy;k++)s[x+j][y+k]='a'+i;
}
main(){
    int n,m,a,b,c,x,y,end=0,i;
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    if((n*m)%2==1)puts("IMPOSSIBLE");
    else{
        if(n%2==1){
            if(m/2>a||(a-m/2)/2+b/2+c<(n-1)*m/4){
                puts("IMPOSSIBLE");
                end=1;
            }
        }
        else if(m%2==1){
            if(n/2>b||(b-n/2)/2+a/2+c<(m-1)*n/4){
                puts("IMPOSSIBLE");
                end=1;
            }
        }
        else if(a/2+b/2+c<n*m/4){
            puts("IMPOSSIBLE");
            end=1;
        }
        if(end==0){
            if(n%2==1){
                for(i=0;i<m;i+=2){
                    fill(n-1,i,1,2);
                    a--;
                }
            }
            if(m%2==1){
                for(i=0;i<n;i+=2){
                    fill(i,m-1,2,1);
                    b--;
                }
                m--;
            }
            x=y=0;
            while(x<n-1){
                if(y>=m){
                    x+=2;
                    y=0;
                    continue;
                }
                if(c>0){
                    fill(x,y,2,2);
                    c--;
                }
                else if(a>1){
                    fill(x,y,1,2);
                    fill(x+1,y,1,2);
                    a-=2;
                }
                else{
                    fill(x,y,2,1);
                    fill(x,y+1,2,1);
                    b-=2;
                }
                y+=2;
            }
            for(i=0;i<n;i++)puts(s[i]);
        }
    }
}