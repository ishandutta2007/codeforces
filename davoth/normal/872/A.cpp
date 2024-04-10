#include <iostream>
using namespace std;
int main(){

int m,n,t,s,q1=false,q2=false,q3=false,q4=false,q5=false,q6=false,q7=false,q8=false,q9=false,p1=false,p2=false,p3=false,p4=false,p5=false,p6=false,p7=false,p8=false,p9=false,p,q;
cin>>m>>n;
p=9;
q=9;
for(m;m!=0;m--){
    cin>>t;
    if(t<q){
        q=t;
    }
    if(t==1){
        q1=true;
    }else if(t==2){
        q2=true;
    }else if(t==3){
        q3=true;
    }else if(t==4){
        q4=true;
    }else if(t==5){
        q5=true;
    }else if(t==6){
        q6=true;
    }else if(t==7){
        q7=true;
    }else if(t==8){
        q8=true;
    }else if(t==9){
        q9=true;
    }
}
for(n;n!=0;n--){
    cin>>s;
    if(s<p){
        p=s;
    }
    if(s==1){
        p1=true;
    }else if(s==2){
        p2=true;
    }else if(s==3){
        p3=true;
    }else if(s==4){
        p4=true;
    }else if(s==5){
        p5=true;
    }else if(s==6){
        p6=true;
    }else if(s==7){
        p7=true;
    }else if(s==8){
        p8=true;
    }else if(s==9){
        p9=true;
    }
}
if(q1&&p1){
    cout<<1;
}else if(q2&&p2){
    cout<<2;
}else if(q3&&p3){
    cout<<3;
}else if(q4&&p4){
    cout<<4;
}else if(q5&&p5){
    cout<<5;
}else if(q6&&p6){
    cout<<6;
}else if(q7&&p7){
    cout<<7;
}else if(q8&&p8){
    cout<<8;
}else if(q9&&p9){
    cout<<9;
}else if(p>q){
    cout<<q<<p;
}else if(q>p){
    cout<<p<<q;
}
return 0;
}