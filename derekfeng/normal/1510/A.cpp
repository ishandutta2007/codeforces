#include<bits/stdc++.h>
using namespace std;
char c[103];
int n,mch[103];
int ub[103][103],lb[103][103],w[103][103]; 
char ans[1145][1145];
void exprdfs(int l,int r); 
void operationdfs(int l,int r){
	ub[l][r]=lb[l][r]=1;
	if(l==r){
		w[l][r]=5;
		return;
	}
	if(mch[l]==r){
		exprdfs(l+1,r-1);
		w[l][r]=w[l+1][r-1];
		ub[l][r]=max(ub[l+1][r-1],ub[l][r]);
		lb[l][r]=max(lb[l+1][r-1],lb[l][r]);
		return;
	}
	operationdfs(l,r-1);
	w[l][r]=w[l][r-1]+6;
	if(c[r]=='+'){
		ub[l][r]=ub[l][r-1];
		lb[l][r]=lb[l][r-1]+2;
	}
	if(c[r]=='?'){
		ub[l][r]=1;
		lb[l][r]=lb[l][r-1]+ub[l][r-1]+2;
	}
	if(c[r]=='*'){
		ub[l][r]=1;
		lb[l][r]=lb[l][r-1]+ub[l][r-1]+4;
	}
}
void exprdfs(int l,int r){
	bool dividing=0;
	for(int i=l;i<=r;){
		if(c[i]=='|'){
			dividing=1;
			break;
		}
		if(c[i]=='(')i=mch[i]+1;
		else i++;
	}
	ub[l][r]=lb[l][r]=1; 
	if(dividing){
		vector<pair<int,int> >pars;
		int lst=l-1;
		for(int i=l;i<=r;){
			if(c[i]=='|'){
				exprdfs(lst+1,i-1);
				w[l][r]=max(w[lst+1][i-1]+6,w[l][r]);
				pars.push_back(make_pair(ub[lst+1][i-1],lb[lst+1][i-1]));
				lst=i,i++;
				continue;
			}
			if(c[i]=='(')i=mch[i]+1;
			else i++;
		}
		exprdfs(lst+1,r);
		w[l][r]=max(w[lst+1][r]+6,w[l][r]);
		pars.push_back(make_pair(ub[lst+1][r],lb[lst+1][r]));
		ub[l][r]=pars[0].first;
		lb[l][r]=pars[0].second;
		for(int i=1;i<pars.size();i++)lb[l][r]+=pars[i].first+pars[i].second+2;
		return;
	}
	int cnt=0;
	for(int i=r;i>=l;){
		if('A'<=c[i]&&c[i]<='Z'){
			int j=i-1;
			while(j>=l&&'A'<=c[j]&&c[j]<='Z')j--;
			int len=i-j;
			i=j;
			w[l][r]+=len+4;
			cnt++;
			continue;
		}
		if(c[i]==')'){
			exprdfs(mch[i]+1,i-1);
			w[l][r]+=w[mch[i]+1][i-1];
			ub[l][r]=max(ub[l][r],ub[mch[i]+1][i-1]);
			lb[l][r]=max(lb[l][r],lb[mch[i]+1][i-1]);
			i=mch[i]-1;
			cnt++;
			continue;
		}
		cnt++;
		int j=i-1;
		while(j>=l&&(c[j]=='*'||c[j]=='?'||c[j]=='+'))j--;
		if(c[j]==')')j=mch[j];
		operationdfs(j,i);
		if(l!=j||r!=i)w[l][r]+=w[j][i];
		ub[l][r]=max(ub[l][r],ub[j][i]);
		lb[l][r]=max(lb[l][r],lb[j][i]);
		i=j-1;
	}
	w[l][r]+=2*(cnt-1);
}
void chardfs(int l,int r,int p1,int p2);
void operationchar(int l,int r,int p1,int p2){
	if(l==r){
		ans[p1-1][p2]='+',ans[p1-1][p2+1]=ans[p1-1][p2+2]=ans[p1-1][p2+3]='-',ans[p1-1][p2+4]='+';
		ans[p1][p2]='+',ans[p1][p2+2]=c[l],ans[p1][p2+4]='+';
		ans[p1+1][p2]='+',ans[p1+1][p2+1]=ans[p1+1][p2+2]=ans[p1+1][p2+3]='-',ans[p1+1][p2+4]='+';
		return;
	}
	if(mch[l]==r){
		chardfs(l+1,r-1,p1,p2);
		return;
	}
	if(c[r]=='+'){
		operationchar(l,r-1,p1,p2+3);
		int R=p2+w[l][r]-1;
		ans[p1][p2]='+',ans[p1][p2+1]='-',ans[p1][p2+2]='>',ans[p1][R-2]='-',ans[p1][R-1]='>',ans[p1][R]='+';
		for(int i=1;i<=lb[l][r-1]+1;i++)ans[p1+i][p2]=ans[p1+i][R]='|';
		int D=p1+lb[l][r-1]+2;
		ans[D][p2]='+',ans[D][p2+1]='<',ans[D][R]='+';
		for(int i=p2+2;i<R;i++)ans[D][i]='-';
	}else{
		operationchar(l,r-1,p1+2+ub[l][r-1],p2+3);
		int R=p2+w[l][r]-1;
		ans[p1][p2]='+';
		for(int i=p2+1;i<=R-2;i++)ans[p1][i]='-';
		ans[p1][R-1]='>',ans[p1][R]='+';
		int D=p1+ub[l][r-1]+2;
		for(int i=p1+1;i<D;i++)ans[i][p2]=ans[i][R]='|';
		ans[D][p2]='+',ans[D][p2+1]='-',ans[D][p2+2]='>',ans[D][R-2]='-',ans[D][R-1]='>',ans[D][R]='+';
		if(c[r]=='*'){
			int DD=D+lb[l][r-1]+2;
			for(int i=D+1;i<DD;i++)ans[i][p2]=ans[i][R]='|';
			ans[DD][p2]=ans[DD][R]='+',ans[DD][p2+1]='<';
			for(int i=p2+2;i<R;i++)ans[DD][i]='-';
		}
	}
}
void chardfs(int l,int r,int p1,int p2){
	bool dividing=0;
	for(int i=l;i<=r;){
		if(c[i]=='|'){
			dividing=1;
			break;
		}
		if(c[i]=='(')i=mch[i]+1;
		else i++;
	}
	if(dividing){
		vector<pair<int,int> >pars;
		int lst=l-1;
		for(int i=l;i<=r;){
			if(c[i]=='|'){
				pars.push_back(make_pair(lst+1,i-1));
				lst=i,i++;
				continue;
			}
			if(c[i]=='(')i=mch[i]+1;
			else i++;
		}
		int R=p2+w[l][r]-1;
		pars.push_back(make_pair(lst+1,r));
		for(int i=0;i<pars.size();i++){
			ans[p1][p2]='+',ans[p1][p2+1]='-',ans[p1][p2+2]='>';
			chardfs(pars[i].first,pars[i].second,p1,p2+3);
			ans[p1][R]='+',ans[p1][R-1]='>';
			int j=R-2;
			while(ans[p1][j]==' ')ans[p1][j]='-',j--;
			if(i<pars.size()-1){
				int nxt=p1+lb[pars[i].first][pars[i].second]+ub[pars[i+1].first][pars[i+1].second]+2;
				for(int j=p1+1;j<nxt;j++)ans[j][p2]=ans[j][R]='|';
				p1=nxt;
			}
		}
		return;
	}
	int cnt=0,now=p2+w[l][r]-1;
	for(int i=r;i>=l;){
		if(cnt!=0)ans[p1][now--]='>',ans[p1][now--]='-';
		if('A'<=c[i]&&c[i]<='Z'){
			int j=i-1;
			while(j>=l&&'A'<=c[j]&&c[j]<='Z')j--;
			int len=i-j,L=now-len-3;
			ans[p1][now]=ans[p1-1][now]=ans[p1+1][now]=ans[p1][L]=ans[p1-1][L]=ans[p1+1][L]='+';
			for(int i=now-1;i>L;i--)ans[p1-1][i]=ans[p1+1][i]='-';
			for(int k=j+1,l=L+2;k<=i;k++,l++)ans[p1][l]=c[k];
			now=L-1;
			i=j;
			cnt++;
			continue;
		}
		if(c[i]==')'){
			chardfs(mch[i]+1,i-1,p1,now-w[mch[i]+1][i-1]+1);
			now-=w[mch[i]+1][i-1];
			i=mch[i]-1;
			cnt++;
			continue;
		}
		cnt++;
		int j=i-1;
		while(j>=l&&(c[j]=='*'||c[j]=='?'||c[j]=='+'))j--;
		if(c[j]==')')j=mch[j];
		operationchar(j,i,p1,now-w[j][i]+1);
		now-=w[j][i],i=j-1;
	}
}
int main(){
	scanf("%s",c),n=strlen(c);
	stack<int>st;
	for(int i=0;i<n;i++){
		if(c[i]=='(')st.push(i);
		if(c[i]==')') mch[st.top()]=i,mch[i]=st.top(),st.pop();
	}
	exprdfs(0,n-1);
	printf("%d %d\n",lb[0][n-1]+ub[0][n-1]+1,w[0][n-1]+6);
	for(int i=0;i<1145;i++)for(int j=0;j<1145;j++)ans[i][j]=' ';
	int H=lb[0][n-1]+ub[0][n-1]+1,W=w[0][n-1]+6,L=ub[0][n-1];
	ans[L][0]='S',ans[L][1]='-',ans[L][2]='>';
	ans[L][W-1]='F',ans[L][W-2]='>',ans[L][W-3]='-';
	chardfs(0,n-1,L,3);
	for(int i=0;i<H;i++,puts(""))for(int j=0;j<W;j++)putchar(ans[i][j]);
}