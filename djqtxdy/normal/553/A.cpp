#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
/*
uLuu2uULjJU2kXqSXkF152F25u12F55U51F5SFk55UUu55PPP552FUUuuLLLJL10OGBBBMMMMOMGMGNF2JujU2k5FFXkXkXFkFk5SFS5F1F5S1S5S5S5S1S5522uUu2u1u2U2u2u2u2uuFOG8Z88MZ
J7LYLYvLvLLuj7i:iYjjJuuUYjYUuujujujuu15FUUjuU51FUuJJvLJUSNE8ZMMBMMOMOO8M8OOMOBMMOO0qF1uuj1551S2FU125U525U2u1U1U1u2u2U1UUuUYJYjYJLjYuLuYJJuYYv2ZGNZEGZG
uLuuuYujuu2UL,   :JjUu1uUuUU1U2uUu2251FFSFS5S12JJJU1ZO@M@@@B@MO0GZ8OMOMOMOMOMMMMBM@B@MMZX222kFSFkSk5F1F555S1F5F1F1F1S1F15uUuUuUuUu2u2uUu2uUuuF8GGG88OZ
LLJuJuJuJuLLi:  .iLuYUUUuuj2U2uUu2u521UF11uuYYY1POM@BBM@BBOOE8OMMMMMMBMBMMMMMMMBMMMMMBB@BB8N155k5kFS1F15155F1F1S5F1F5F51U2u2uUuUuUuUu2uUuUuUJkG8Z8ZOGG
7:77v7v77ri,::ir7LJj125U2uUu2uUuUU125uuujvLYSE@B@B@MB@@BONGGOE8OOZG8OOOOMMMMMOMOMMMMMMMMBM@BMX2U11S1F1F551F155F1F152F1F11u2u2u2uUu2uuuUuUuUuj58ZGZG8OE
::iiirrrii:::rvJr::i7YJUuuuUu2uUuUJ225ujYFE@B@B@MMOB@MZEZOGO0EEGqEZO8O8MMMOMOMOMOMOMOMOBMBMB@@MquU1S1S5F1F151F55251F252F21uUu2uUu2u2uuuUuuu2jkZ80GZGGG
:.::::i:::::rr77i    :LuUjuuUu2u2juYuJSEMB@BBBBO8OBMOZG8O8OEZGO8OOMMMOMMMMMMMMMMMMMOMOMMMMBMBMBBO51UF1515151F1F25252F1555UUuUu2uUuuuUuUuuu2uu58ZZEGZ8G
,.,:::,:,::iirr7i,  ,LuujujuuUjUuUvJFZMMMMMBMMGEZMMMOMOMOMOOGOOOOMOO8OMB8OOMMBMMMMMMMMMMOMMMMBM@B@Z2j2251F151F15152F2F2FU1u2uuuUuUuUuUuUu2uUuk880GZ8Z8
. ,.,...,,::iirr7rLJ12UjuJuYuuuJLvkOBOMOMOBMMOGZOOO8OOMMOGOOOMMOBMMMBMMMMOMMMOMMMOMOMMMMMMMMMMMM@M@Mkj2155F5F1F152F252525u2U2uuuUuuuuuUuUu2uuSOZ8Z8Z8Z
. .....,,:,:iirrrvjF22uuJJYjJJL77kMM8MMMMMOMMMZNNGZO8GZ80ZEZqNNGGON0GMOMMBMBMBMMMBMMMMMMMMMMMBMBMBB@B8uu1S1F25152515112512U2U2uUuUuuu2uUuUuuJk8OG8ZGEG
. . ....:,::ii;rr7uu2UUjujjYJv7uMM88MOOGMGZOMZ0S0EOOO8OEEEZ0GZGZOGO8OOMMMMMMBMBMMMMMBMMOMMMMMMMMBMBM@BM2U2F1F2F251525251Fu2u2uuuUuUuuUUuUuUuuSOGGEZE8E
   ....,,::::iir;vYujujuujYL7YN@MMOMOO0EE8OOPqXXqOMMOOOOZ88O8OOMOMMMMMMMMMOM8M8MOMMMMMMBMMMMMBMBMBMBMB@B1U2F2S5F1F2F151F22uUu2u2u2uUuUuUuUuujP88EGZGEZ
. ....,,:,::::iirLujuuUjjYv7qB@O8OM88000MGE122S0OOMGOEGZO8O8O8MOMMMOMMMOMMMOMOM8M8MMMOMMBMBMBMBMMMBMBM@BB5u11551515151F25UUu2uUuUuuuUu2u2u2uuFOEGZZEG0
  .......,::iiirvYYuuuYjYL7EBBZ88BO8PEGMBP7vLFkG8M8OGOZZZO8MOMOMMBMMMMOMMMMMMMMMMMOMOMOMMBMBMBMBMBMBMBMBBMU15F152F25252521u2uUuUuUuuuUuUu2uujXGGEGEG0E
. . .     ..::;rLYuJuJjJvLO@ME8MMOGNEZMEGu;72S8Z8EEN00Z0OMMMMMMMMMMMMMOMMMMMMMBMMMMMMMMMBMBMBMBMBMBMBBBM@B8u5152515251F15U2u2uUu2uUuuuUu2UUjj58ZGZZZZE
             ..:rLLjJULvLMBMG8OMO8kkkZXU777jkZEZZOZG0ENZGMMMMBMMMMMMMMOMMBMBMMMMOMOMMBMMMBMBMMMBMBMBMBMBM@BFu11F25152F1F22u2uUu2uUu2uUuUU1JJv2Z8GG0ZEZ
    .......    .:i7YuLvJMBMGOGMO8NXSSS1i,:u2PZOEZEOOMMMOMOMMBMMMMMMMMMMOMOMMMOMOMOMMMMBMMMBMMMBMBMBMBMBMBM@GuU52515151511u2uUu2u2u2uUuUu1uY77uOZ8EZ0ZE
   . .....,:...i;r7jL7U@BMZOOMOM0FUXqFYi:uqGE8ZO8OGMGOMBMMMMMMMMMMMMMMMMMOOMOMMMMBOBMBMBMBMBMBMBMBMBMBMBMMB@Fu1515152F1F21uUuUu2uUuUu2u1UUv7;UOGEGEZ0Z
. ....,.,,:,::rJ2JuLvF@MM8MM@MM80kP5Sk02S08ZO88ZZEG8MMMMMMBMMMBMBMMOMMMMMMMMMMBMBM@MBMBMBMBMBMBMBMBMBMBMBMBBMu52F2F152515UUu2u2u2uUuUu2U2YL77UMZGZ80ZE
. ....,::::r7juUuuL75@B@@@MMGZXXSPSF1u2ESFUFkq0GZ8GOMMMBMBMMMMMMMBMBMMOMMMOMMMMMOMMBMBMBMBMBMBMBMBMBMBBBMBM@B5u515155555U2uUu2uUuUuUu2u2UY77r5O8EZEG0Z
. ..,:ir7Lu1k51JuYvJ@BBB@MkLLLJLLv7ir:;Yv7LLLL5qGGMOMMMMBMMMBMMOMMMMBMMMMOMMMMMMBMBMBMBMBMBMBMBMBMBMBMBMBMBM@Eu151F1F5F11uUuUuUuUu2uUu1UUvvrr2MGGEGEZE
i:rvLU5kXkuJLU22YYvOB@B@Muri:,,i:i:::,:7ri7rrLuX50GMOMMMMMMMMBMBMMMMOBMBMBMMMMMBMBMBMBMBMBMBMBMBMBMBMBMBB@MBBBuF1F1F2F15UUu2uUu2uUU2u1U1YL77r1OOEG0ZEZ
P2qPPS1Lvi:.:7uujvXB@G@Bu:... ..,.,,..,:r:7r:rUU55XEOOOOMMMOMMMMMMMMMMMMBMMMBMMMBMMMBMBM@BBMBM@MBMBMBMBMBBBM@BFuF1F1F1515uU252F25252F212u77r72OZZ0Z0E0
v77r::,.    ,Luu7jM@B0OO:. . ......,...:i:,riiruUJ2PZOEZZMMMMMMMMBMMMMMBMBMMMBMBMBMBMBMBMBM@MBMBMBMBMBMBM@MBB@ku252F2F1521u55S5S5kFk1F55JL77rS8GEG0E0E
           .ruULvP@MOq8j................ii..ii:7uJu1qNOGZZMOMMBMMMBMMMBMBMBMMMBMBMBMBMBMMMBMBBBBBMBMBMBMBMBB@BOu115552F55U22F1SFkSXkk1SUuvvr7k80Z0Z0Z0
       .   :vUJLvMB81qZi ................;,.,::;7vu11qSZEqEG8MMMOMMBMMMBMBMBMBMBMBMBMBMBMBMBM@MBMBMBMBMBMBMBM@OUUF5F252512U12FFkFXkP5F51JL7vvqGZNEEZ0E
. . . .   .iuuuLjB@XSZO,..........,...,.,i7,,:::iiLJJJSkG00qN0OOMMMMMMMMBMBMBMBMBMBMBMBBBMBMBMBMBMBMBMBMBMBB@BMU15F155F25U1U55FSSFXSS1SUJvv7JP8EZ0Z0ZN
   .      ,7jujYj@B15O1,...,.,...,.,.,,,.:7i.::::ir77vJ5SEqqqXkGOMMMMBMMMBMBMBMBBBMBMBBBMBMBMBMBMBMBMBMBBBMBM@OU1S5S5S5521U12F5SFkSk1F2ULL7Lu0ZG0E0Z0Z
. . .    .rLujuLUBZ2UBL.,,,.,.,.,.,.,,,,.::ri,i:iirrr77LU1qkN0Pq88OOMMMMMMBMBMBMBMBMBBBMBMBM@MBMBMBBBMBMBMBM@@OuFFS1S1S15252F5kFXSXFSFFJYvvL5P8EGEE0EN
. .. ....:7jJuYYj@P5S8:,,:,:,,,,,,.,.,,,,::ir::i:i;ri7rriL1P2PSkqOGOOMMBMMMBMBMBMBMBMBMBBBMBBBMBBBMBM@BBMBMBB@qU5S5S1F552F2S5kSkSPkXFF1uLvvu2E0G0Z0ENZ
. ......,iLYuJuv1BO7SE.,:,:,,,,.,.,,,,,,::i:rriii:i;ii;r7r7S1YSUJkOZ8OMMBMBMBMBMBMBMBMBMBMBMBBBMBBBMBB@BBMBB@M1US5S5F5F1F211F5XSXSPFk52YLvLuFqE0E0E0Eq
. ......:7vYYjJLu@ZLUU ,,,,:,,,,,,,,,,,::::::r:iii:;iiiii7;r5JuSYuk8E8OMMBMBMMBBMBMBMBBBMBBBBBMBMBBBMBM@M@MBBOu11S5S5S5F152F1kFkSPSkFSUjLLvU100ZNE0E00
. ......ivJLYLuvUBNL2i .,.,,:,:::::,:::::,:,::r;iiiii:iiii7iYUvu1vJqZq8OMMBMBMBMBMBBBMBBBMBMBBBMBB@B@MMMBBBM@XU1F1S5F5S55251FSkFSSXFk52LY7vjFPG0ENENZP
. .....:rjYJLjJju@EY57....,,,,,:::,:,:,::::::::ri::::iii:iii;Uvv11L208E8OBMBMBMBMBMBMBMBBBBBMBMBMBB@MBB@B@B@B5ukFS1S5F5F252F5SFF5kFkFFuLvvvU500EN0NZ00
. ,.,.,:LJJLjYuLuB@1E2r:. .,,,:,:::::::,::::::::i::,::i:iiii;LuruujLFEZ88OMM@MBMBMBMBMBMBM@B@B@BBB@BBB@M@BBB@k25S5S5F5S5F251S5S5F5S5k12Lv7LuFNEqEP00GN
. .,..:rLuYJYujJYBBMGZMB0Uri::,:::::::::,,,:.,.,.::,.,:::iiiiruJvuYJ7FPX08GOMBMBMBMBMBMBMBB@BBB@MBB@B@BBB@M@@PUS1S5F1S5F15U51F1F5F5S5FuJvLL1100ENNqEE0
, ,.,,i7UJJLjJuJLMM8M18M@B@q1r::::::iirri:iri::,:,ir::i,:::iri7jv2LLLvSuu0ZqOOMMBM@BBMBMBMBBBMBMBB@BBBBBBB@MBk1FFFFFS5SF525252515251F1uLLvJUSXZNEq00ZN
...,.:rJuuJJJuuuYZMXO:::iYFEP1r::::i7u255kXEqEkS52LuUYvLi:::iriLvUU77JLFJuX0P8OOOMMBMBBBMBMBBBBBBBB@B@B@M@B@MSUk1S5S5F5S1521252525U515uYvvL25N0E00qEEE
, ,.:ivJuLJYJjujjF@ZB:  ..:rYuu;iiii7L2u11kq0GMMMOOXNkXkkuJiiiirL72rrvLu2LUXkX8OMOMMBMBBBBBB@BBB@BBMBMBMBMBBMFFSX5k5F5F5F11U1U125U5U5UULLvYuFPZE0X0EEN
::ir7YjuJjJjLjuujuO@Mv   .,:rLYviii;;7vJYYYUYvLuu5ju505kPkFjri:r77Yvi7LvJULuSXq8OM8MMBB@B@B@MMOBB@B@B@BBM@MBPkFkFk1F5SFS5F21U121252512JYLYL21qEZqqPG0E
Y7ju2UUJuJuJuu2jULkBBiiLii::i7Yj7:iir7LY2JY7:..,:iiiiYJ7JuuJLrrirrLv;ivvvuuLFk0N8MMOMMMMMMMZ8OZXPqEM@B@B@B@BGSkFkSS5k5F1FU2U1UUU2U1u2u2jjJu2FqENNkqNE0
uJjuJUjuJjYjYuuUuuY@B,5@MOBMq2U2Ui,iir7JU1ur,,..:::::rvri77Lv7r;ir7J;i:LvvJuLFP80OMMOM8EqPkkPZ8MZPjjXMMBB@O80FFSSk5SFF1S11U121u2U2u1U2U2u12F5N0EqqXE0Z
jLuJuJuJuYuJuJ2uUuJBZ i:jq@@@OGuui..::r7j21Yr:::irri;r77;rr777riri7j7:iivrLJvu0EOZOMOOqSF22XG0qk8OGUL1jU@OXPPFkSXFS5S5F21U1U52121U525U1211F5SPE00XNN0N
JLYuJuJuJujuYuu2uUUM:  .:7Luu11ur.  .,:i;7u@BGXSUUuuuUukYJLL7v77riiLv::i;7LULLPEGZZMMOk1UuJNGOESUqOE2NJ1BOSXSSFXSXFkFk5F252515152F2F2515U55SFqNENqP0qE
uvujuuujuJuJujUuUuSk  ..irLJ5u7:,   .,::iivSEM@B@B@B@BMOE21uLrrii:i7ui:irrLY5LSEZE88M8ZU2Y7LJ2kSPNEu1SuG@B8XkFkFkkXSkFk5F15152F25251F21255kFSqEq0PqqEq
uYJuuujuuuJujUu2u2F5   ..:,:.. .   .,,,:,::;7uu2YjLJ77::;....,.:,,.rj7:irrvLYuj0NGGGOONkYJv2JUkqqN2Yuvv@BBBBF2FPFkSXSk5k5F2F15252525252F5kSkFEN0qqXENZ
2LujUuUuujuJuu2UUUXU  .....       .,,,,.,.:.:ruUU2UjL77:7.. ....,,.:Yri:irvLjvuX80GE8MNkJuZ00FuuuJ157:GBBMMB@021XSkFkFkSF21252F1F2F555F1kSXkkPZq0kNNEq
uLuujUuuuUuuuuU2u15F           . ..,,:,,.,.,..,:ivrvri:,r:.,..,:.:,,Yrri:r77YYLUEOXqXGOqFUuL7rivuJ7:rMBBMMOMB@Z51kFXSXSS152F2F1525151F1F5kSXSqEEPPqZ00
uLUuuuUjUuuuuj2uUUFF. . ..  ...   ..,,:,..,.... ..,.. ..:.,,,,:,:::.YvrriiLrvjjvSOEX12MNPuLj7rvJui:J@@@BMOMOMM@OX2SSXSXSS112F252F1F1F5F5SFXSXPZ0NXNNZ0
uJuUuUuUjuuujUu1u2FX, ....,:vv .,..,.,,::::......... ...::.,,:::::,:rUi7i;77rJYYuZSqFuXOk57j77;;:vO@B@B@MMMMMBM@Mq1kkNSPSS5S1F1F1F151F1kSkSkkN0NPqPE0G
ULUu2uuuUuujujUU1u1Pr ..,:i7j. .,.....,:::L7,........ ..::.,::::::::i5ri7irr7v1LU0kSFYFGGFLrr,iLE@@B@MBBBMMMBMMMBMEkXP0qNkk5F1F1F5F1F5S5SFXSkPGENXNNGE
uJu2u2uUuUu2juu1U1uS5..::i7J  .... ..... .,JUi,.:,.,...,::.::::::i:::Uvirrrr77YJYqFk1uuE0F7:;UM@B@BBMBBBMBOBB@MBMMMOPPq0qNXXSSFS5F1F5F1SFkSXSNG8PPqE08
uLuuUuuu2u2uUu121U2UXL.:iiYr .,::.,.,.     :Gqr::,::,,,.i,,,::::i:i::7Li77ri77LLJFFF1UJ0NFPNB@@B@MBBBMBM@BBMBMBMBMBMMPqq0N0XPkS5S5S1S1SFSSXSXqGENXq0ZZ
uJu2uUuUU2uuj2U5U2u21P;,:rvJ:::i::,:.. ..,:7MZLv::::::,:::,::::iii:i:iL7irrrrLvLj1uPUUuGE8@@@BBBB@MBBBMBMBBBMBMBMBMMMMPkP0NqXP5S1F5F5F5kFXSkkNqGNPPZNG
2YUu2u2u1U2uUu525U2uFFq::rvLvi7vvr7iiiirvjPPXr7j7:i:::::i::ii:iiiiiii:Lvr77rrrLuLj212jXqq0BMBMMB@MBBBMBMBM@MBM@BBMBMMOM0FFNPqkXFS5F5F5kFkkPkkkN00XN0ZE
uju2u2u1u2uUu2U521251FS5::7vri:;7LLUXGG8kX5u777LLLriiiirrri;iiiii;iriiiLi7viir7uLL5XuUUPXMMMMBMBMBB@BBMBBBMBBBM@BBMBMMOMNSPNPqSkSkFkFSFXSPkPSqqEqqqGE8
2J2U12121U2uUUF25U5U115Pu.irv7::::72ESuvrrrii:::7YYrrr7r777rri;i;i;ii::7L:77rrvLuY2k1u2P0OMMBMBBBMBBBM@BBBBM@MBB@BBMBMMOBNXXqXXkkSXFS5kFkkXSkXE00qZZZZ
UuU221U125UU215S5F21251X0u,:rj77777rrri;iri;ii:ii7LL7rrr;rr777;r;rii:i:rLr:77L7LuU251YS0EMMBMMM@MBM@BBB@MBMBMBMBB@BBBBMBMBEPX0q0qNXPSXFXFk5S5PqNqEZ8ZG
1j12F252F21222F5525U5211XEu,:r1SkNqFF2PXF15U225u2jjLjvrir;rrrrrr7i;ii:i:LrrrLYLJSUU12vP088BB@BBMBM@BBM@BBMBMBMBM@B@MBB@OMMMEPX0N0qZq0kXSXFS5XNEqENGEZZ
1U151F1F2521215S5F1522U55P05iir::77Luk11FPqEZGPGZZNP2Y7;iriiiririiii:ii:vLrL7LLu1F2uYuNZ0GM@MBMBMBB@MBB@M@BBMBMMB@BBMBMMMMMMqqXNqEN0PEPqXNXqPENZEEE8ZO
Fu521151F21U525551521U12FFq0qLi .,ir77v7rii::..::::r57r::i;iiriiiiiiiiii7U7LLvjY2FUJu5ZkEPOB@MMBBMBB@B@B@BBBBBBM@B@B@MMMBMMMMXqqNNZ0EqNX0q0P0PZZG0ZZ88
Uu1515152522U51S5S1F1F15FkSXq8u,.::iiii;:::::...  .,iLr::iiii;;riii;iiirr2LvLjuU51LLjkXEPkNBBBMBBBB@BBBBBBMBB@MBMBMBBBMBOM8MMGkEPEN0q0PPPEqEqN0GEGE8EO
Fu51S1525212F1kSF5F152FFkkkkqqMu.:irvL7ii::.,.....::ii7rrrrir;7;iir;r;rr7Yu7JuF2UjuLU1qGkuFG@MBB@B@M@BBB@MBM@BBMMBBB@MBMMMBOBBGkqq0NNXXSPPEEENGZ8E8GGG
5F5S5k5k5F211FFkFS155F5SFPSPkq0M7,ir7v7vrr:i:i:::::iiirv7vrrrrrrrrrrrr7v7LuJukFULuuju5ZPYUUPB@BBBBM@B@B@B@B@MBMBMBBBMBMBMBMOOBOqPNN0PPkPkqq0qEGOZZZOGO
k1k5kFSSXFSFkSPkPFS5SFkSXXqXNPEZG::::::i;irr7r7ir;riiiii77rrrr777rrr777vLL55k1ULYJJvUNSuLj228B@B@B@B@B@B@B@B@B@BBMBBBMBMMMBOOMBZqq0NNkk5XXEq008GOEG8OG
jLLjJjJuuUu2UFkPkqXXXqPqNNXPXPX08j.::ii;iiirrv777777iiiiirr7r7rrrrr77v7LL15PUuLjYLvU0SYuJUu1F8EMB@@@B@B@B@B@B@M@B@MBBBMBMBMMGMMOX0qqPXSkkqPNPEZO88GM88
uvjLYLL77rrrrr7r7vLJ2UkXEN0PPSPX0Ni.;7v7rii:irL77rrr7rrr777r7r7r7777LvjuFF1u1YLYJvUGk7JLuJuu2Fr::,:i7YjLX1r,uBBM@MBM@MBMMMBMMBBOZX0XXSkFqP0PNN88MG8OOZ
SFFF5F21uuLL77ii:::::::r7jUkXqNG0ON::rrvvYL7;7rriiiiirr7r7r7r7r7777YJ2SX2UJ2kvLuLUPP7LvJuuY2uqqFuv7YSX7:..  Y@B@MMMBBBMMMBMMOBMMEqPXSkFkSPPqPGEO88GMOO
SUF1F1F5SFF5F1F22YLrri:::,:i7L1POM@Zr:i7vLJLLL7;iiiiiirr7r777rv7LY1FS55ujJuu5LYLuFFvLL7Luuuu11EMBOMZ17,  .:.uB@BBMBMBMBOOMMOMMBMN5qkXSkkPXqFX0ZZ8EZGOO
225SFS1k5S1F5kkNNNPPSPk5Yvi:,,,i7JFMMk7r7v7LLL77rrrrr7r777r77vL5kPF1jJLjYJjLujL112vLvvvYu12SkGOBGu:    ,.::,7@B@MMMBMBMBMMMMOBMBPFkPSqP0PqXXkGEO8GN0PN
PFPkqkPkXSXSPkNPqXXkqEZEOEZFu77i:..:7F0Fuvv77ii;77vvLLL7vvLYSP0k1jJvLvLvYLL7UJ1UJ7vvv7LuX0G0Svi.    . ...,::uB@OOMMMBMBBBOMMMOMMESPPNP0PENEq0ZOOOZENNS
PXXqXPkPkXSXFkXPkXSXXEN0PqP0N00G5Ji:..:7jXNSjL7v7UuU2Yvu2qP0XSuJ7v7vvLLY7L7LU1YLvvJuUPPX5Ji,     .     ..::;F@BMOBMMMBMBBBMBMMM@0PXqXqPqP0NEN88O8G0ZE0
NkqkPP0PPSPSXSPPXFXXPPEqPSPkPXEZ888qU7i...iJ@B@B. . 70X1kkFUUYJLJvvvYvLvvL25Su2U1uSuLi:.    . .   . ....,:r2BBMOMOMMMMBMBMBMBMBMZSPkqXNPqqNqEEO8MG8ZOZ
521F2kFPkXXXkqqNkXSPP0N0kXSPkqNZEGGMM@M0v, jB@@@,  ..:ru5kkPkPSk1F5F11111kS2Ju7i:..    ..,.    .. .....,.iZ@BMMMOMMBMBBBMBBBMOOBEPq0qqXqX0qENZZOOMGO8O
SUS5F5SFS5S5SFPkqkXPNqNkXSPkqqEEOOBBBOZ27:XBBM@BL ..,..   ::i7777;rii:::r,. ,.. ...,,.,. .. ....:..,,,, 7M@BBOMOMMMMMMBMBMBM@OMMZqZN0N0X0NZEGqEGOOOGOO
PXkXkXSXFk255kFk55251FU1UFFkkNPP2Jr:...,:F@@MBB@O     ..              ..  .....           .. .   . ,..iqB@MMOMOMOMMMMMMBMBM@BBMOXqqqPqPNq0NZ00N8ZG0GEO
*/
//orz tjw
//orz yjz
//author: FST_master ST_master T_master _master master aster ster ter er r
using namespace std;
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct edge{
	int to,cap,rev;
	edge(int x,int y,int z){
		to=x,cap=y,rev=z;
	}
};
struct Max_flow{
	int Siz;
	int src,snk;
	vector<vector<edge> >G;
	vector<int> dist,seen;
	Max_flow(){
		Siz=0;
		src=-1;snk=-1;
		G.clear();
		dist.clear();seen.clear();
	}
	void Set(int x,int y){
		src=x,snk=y;
	}
	void resize(int s){
		Siz=s;
		G.resize(s+1);
		dist.resize(s+1);
		seen.resize(s+1);
	}
	void add_edge(int u,int v,int c){
		edge t1(v,c,G[v].size()),t2(u,0,G[u].size());
		G[u].push_back(t1);
		G[v].push_back(t2);
	}
	void bfs(int s){
		for (int i=0;i<dist.size();i++) dist[i]=-1;
		queue<int> Q;
		dist[s]=0;
		Q.push(s);
		while (!Q.empty()){
			int x=Q.front();
			Q.pop();
			for (int i=0;i<G[x].size();i++){
				int v=G[x][i].to;
				if (G[x][i].cap && dist[v]==-1){
					dist[v]=dist[x]+1;
					Q.push(v);
				}
			}
		}
	}
	int dfs(int x,int dest,int flow){
		if (x==dest) return flow;
		for (int &i=seen[x];i<G[x].size();i++){
			edge &e=G[x][i];
			if (e.cap && dist[e.to]==dist[x]+1){
				int ff=dfs(e.to,dest,min(flow,e.cap));
				if (ff){
					e.cap-=ff;
					G[e.to][e.rev].cap+=ff;
					return ff;
				}
			}
		}
		return 0;
	}
	int dinic(int u,int v){
		int ans=0;
		while (1){
			for (int i=0;i<seen.size();i++) seen[i]=0;
			bfs(u);
			if (dist[v]==-1) break;
			int f;
			while (f=dfs(u,v,INF)){
				ans+=f;
			}
		}
		return ans;
	}
	int Maxflow(){
		return dinic(src,snk);
	}
};
const LL mod=1e9+7;
const int Maxn=1005;
long long fact[Maxn*2];
LL qp(LL x,LL p){
	if (!p) return 1;
	if (p==1) return x;
	if (p&1){
		LL y=qp(x,p/2);
		return y*y%mod*x%mod;
	}
	else{
		LL y=qp(x,p/2);
		return y*y%mod;
	}
}
LL inv(LL x){
	return qp(x,mod-2);
}
LL c(LL x,LL y){
	return fact[x]*inv(fact[x-y])%mod*inv(fact[y])%mod;
}
LL dp[Maxn];
int a[Maxn];
int sum[Maxn];
int main(){
	fact[0]=1;
	for (int i=1;i<Maxn*2;i++) fact[i]=fact[i-1]*i%mod;
	dp[1]=1;
	int n;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	for (int i=2;i<=n;i++){
		dp[i]=dp[i-1]*(c(sum[i-1]+a[i]-1,a[i]-1))%mod;
	}
	printf("%I64d\n",dp[n]);
	return 0;
}