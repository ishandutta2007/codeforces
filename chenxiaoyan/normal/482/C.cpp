/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int lowbit(int x){return x&-x;}
int ppc(int x){return __builtin_popcount(x);}
const int N=50,M=20;
int n,m;
ll fact[M+1];
char a[N+1][M+5];
int same[N+1][N+1];
bool uni[N+1][1<<M];
ll ok[1<<M];
int main(){
	cin>>n;
	if(n==1)return puts("0.0000000000000000000000000000000000000000000000000000000000000000000000000"),0;
	for(int i=1;i<=n;i++)cin>>a[i]+1;
//	int cl=clock();
	m=strlen(a[1]+1);
	fact[0]=1;
	for(int i=1;i<=m;i++)fact[i]=fact[i-1]*i;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)
		for(int k=1;k<=m;k++)
			if(a[i][k]==a[j][k])same[i][j]|=1<<k-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)ok[1<<j-1]=0;
		for(int j=1;j<=m;j++)for(int k=1;k<=n;k++)if(k!=i&&!(same[i][k]&1<<j-1))ok[1<<j-1]|=1ll<<k-1;
		for(int j=1;j<1<<m;j++)uni[i][j]=(ok[j]=ok[j^lowbit(j)]|ok[lowbit(j)])==((1ll<<n)-1^1ll<<i-1);
//		for(int j=1;j<1<<m;j++)if(uni[i][j])cout<<i<<" "<<j<<"\n";
	}
//	cout<<clock()-cl<<"ms\n";
	int ans0[m+2]={};
	for(int j=1;j<=n;j++)
		for(int i=0;i<1<<m;i++)if(uni[j][i])
			ans0[ppc(i)]+=ppc(i),ans0[ppc(i)+1]-=m-ppc(i);
	double ans=0;
	for(int i=0;i<=m;i++)ans+=1.*ans0[i]*fact[i-1]/fact[m]*fact[m-i+1]/(m-i+1)*i;
	printf("%.100lf\n",ans/n);
//	cout<<clock()-cl<<"ms\n";
	return 0;
}
/*1
10
aababbbaabaababababa
ababaababbabaaababbb
ababbababaaaaaabbbab
ababbbbabaabaaababaa
abbabbbaabbbbbbbaaba
baaabbabababbabbaaaa
bababbbbbbaaaabbaaba
babbaabaaabaaaabbaab
babbbaababaabbbbbaab
bbbbabaaababaabbabab
*/
/*2
50
lxxjjqzvryscehlzrovn
lcgcwukiraqpwqmxasim
hixpzynzmbiifkijlyzh
uwnwqbcnfnjpgnaolydg
ffuawposkoktontwnuhx
rmcqktuxpcgynvavzonc
irwidcrsnkqyfzibljvr
eochdutdsytpenzbymvt
juohqxemmmckhmhhewrp
viuryxozhturvovsyzwf
knqibtjhlhdfdaevhsob
jvngfjwpqretvoxcteop
wovdpiruscrfggdchbli
doqxftpoyiqjiyrmdztq
qsdxfubvmbfkcjgbdqsd
aslaepasjguxqrowvldm
ggwczqnflngpoobibmyt
kepnhxeeuauqgaieayjo
ckwmlkfeucdeibkdyrer
ruafkqfijknidiklsfpy
utpvirohxoigaiefzdte
goxfnowyiexqyaqdnscv
humtowqtuvmhkigydnhb
kxtlwefwyemkfralxarl
enondpydbvrlbjtgldde
mnsummccmbonacwgggji
wgjufvlncycaovoctwyw
cytcvssvlgoycdgwzndh
mudoxcyaxuigyifaosqw
ctllupomceglctmtrepe
zxesnmkunmgeherkirmb
djpqljnbrmhjiduffsno
jvqysqnnbtgxpusykdki
ndcvdgttpiwixukpsfdw
wpzodjquogtbvokdwnxe
ttyrwdwzaukyebtysfbw
ynbkgpfdajcpvymxnjok
bjntilabtzjcyeebfsdf
ycmugxtcrmuklhpgormx
haphhjlhekuafvvjhbkr
jtjaxfzzfddogihrmuca
fecoonpywslqoflpelvm
szsubkkeawmazfhpkiuq
fjbpzceuvrmkubidbvee
wxhkszoqgovodzmzmvyl
rqynhwdpvdwmztvwtdrs
ycqchansuhfrkzvznfen
urwjskdxtktvbqfozfcz
wqzynnbjirtmpfcvvlav
nupvwyctmbgqxlomefgl
*/