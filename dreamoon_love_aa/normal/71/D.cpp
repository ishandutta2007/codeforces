#include<stdio.h>
int a[52][52],joke[2][2],used[64],n,m;
int abs(int x){return x<0?-x:x;}
bool Test2(int x,int y){
    int i,j,d[4],e[14],cnt1=0,cnt2=0;
    for(i=0;i<4;i++)d[i]=0;
    for(i=0;i<14;i++)e[i]=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            if(d[a[x+i][y+j]>>4]==0){
                cnt1++;
                d[a[x+i][y+j]>>4]++;
            }
            if(e[a[x+i][y+j]&15]==0){
                cnt2++;
                e[a[x+i][y+j]&15]++;
            }
        }
    return cnt1==1||cnt2==9;
}
bool Test(int &x1,int &y1,int &x2,int &y2){
    int i,j,ii,jj;
    for(i=0;i<n-2;i++)
        for(j=0;j<m-2;j++){
            for(ii=0;ii<n-2;ii++)
                for(jj=0;jj<m-2;jj++){
                    if(abs(i-ii)<3&&abs(j-jj)<3)continue;
                    if(Test2(i,j)&&Test2(ii,jj)){
                        x1=i;
                        y1=j;
                        x2=ii;
                        y2=jj;
                        return 1;
                    }
                }
        }
    return 0;
}
void print(int x){
    int y=x&15;
    if(y==1)printf("A");
    else if(y>1&&y<10)printf("%c",'0'+y);
    else if(y==10)printf("T");
    else if(y==11)printf("J");
    else if(y==12)printf("Q");
    else if(y==13)printf("K");
    switch(x>>4){
        case 0:
            printf("C");
            break;
        case 1:
            printf("D");
            break;
        case 2:
            printf("H");
            break;
        case 3:
            printf("S");
            break;
    }
}
bool dfs(int x){
    int i,j,x1,y1,x2,y2;
    if(x==2){
        if(Test(x1,y1,x2,y2)){
            puts("Solution exists.");
            if(joke[0][0]==-1&&joke[1][0]==-1)puts("There are no jokers.");
            else{
                if(joke[0][0]!=-1&&joke[1][0]==-1){
                    printf("Replace J1 with ");
                    print(a[joke[0][0]][joke[0][1]]);
                    puts(".");
                }
                else if(joke[0][0]==-1){
                    printf("Replace J2 with ");
                    print(a[joke[1][0]][joke[1][1]]);
                    puts(".");
                }
                else {
                    printf("Replace J1 with ");
                    print(a[joke[0][0]][joke[0][1]]);
                    printf(" and J2 with ");
                    print(a[joke[1][0]][joke[1][1]]);
                    puts(".");
                }
            }
            printf("Put the first square to (%d, %d).\n",x1+1,y1+1);
            printf("Put the second square to (%d, %d).\n",x2+1,y2+1);
            
            return 1;
        }
        return 0;
    }
    if(joke[x][0]==-1){
        return dfs(x+1);
    }
    for(i=0;i<4;i++)
        for(j=1;j<=13;j++){
            
            if(used[(i<<4)+j])continue;
            used[(i<<4)+j]=1;
            a[joke[x][0]][joke[x][1]]=(i<<4)+j;
            if(dfs(x+1))return 1;
            used[(i<<4)+j]=0;
        }
    return 0;
}
main(){
    int i,j;
    scanf("%d%d",&n,&m);
    joke[0][0]=joke[1][0]=-1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            char s[8];
            int tmp=0;
            scanf("%s",s);
            if(s[0]=='J'&&s[1]>='0'&&s[1]<='2')tmp=-(s[1]-'1');
            else{
                if(s[1]=='C')tmp=0;
                else if(s[1]=='D')tmp=16;
                else if(s[1]=='H')tmp=32;
                else if(s[1]=='S')tmp=48;
                if(s[0]=='A')tmp+=1;
                if(s[0]=='T')tmp+=10;
                if(s[0]=='J')tmp+=11;
                if(s[0]=='Q')tmp+=12;
                if(s[0]=='K')tmp+=13;
                if(s[0]>='1'&&s[0]<='9')tmp+=s[0]-'0';
            }
            a[i][j]=tmp;
            if(a[i][j]>=0)used[a[i][j]]=1;
            if(a[i][j]<=0){
                joke[-a[i][j]][0]=i;
                joke[-a[i][j]][1]=j;
            }
        }
    }
    if(!dfs(0))puts("No solution.");
}