#include <bits/stdc++.h>
using namespace std;
/*
Coded by 
The most charming girl in the world
@@@@@@@@@@##&|;!!!!!!!!!!||||||||%%%%%$$$$$$$$$$$$%%$$$&&&&&&&&&$$&&&&&&&&&@@@&%||||||$&&&&@&%;'```'`':!||%&@@@@#@&&&&&@@@&&$$$&&@@&$$$&@@@@@@@@@@@@@#@@@@@@@@@@#@@@@@#@@@@@@@@@@##$
@@@@@@@@@####$!;!!!!!!!!!||||||||%%%%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&@@@@@@&%|||||!:'`'!$&&&&&&%:''!|||$&&&@@@@@@&&&&&@@@&$$$&&@&&$&&@@@@@@@@@@@@@@@@@@@@@@@@##@@@@#@@@@@@@@@@#@%
@@@@@@@@@####@|;!!!!!!!!!|||||||%%%%%%%%%%%%%$$$$$$$$$$&&&&&&&&&&&&&&&@@@@@@@@&%|;:'''''``````'!$&&&@@&|:;%$$&&&@@@@@&&&&&@@@&$$$&&@@@@@@@@@@@@@@@@@@@@@@@#@@@@@#@@@@@#@@@@#@@@@##@%
@@@@@@@@####@@&|;!!!!!!!!|||||||%%%%%%%%%%%%%%$$$$$$$$&&&&&&&&&&&$$$&&@@@@@@@@@@&$|;'''''````````'':!$&&&$%%%%$$&@@@@@&&&&&@@@@&&&@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@#@@@@#@@%
@@@@@@@#####@@@$!;!!!!!!|||||||%%%$$$$$%%%%%%%%%$$$$$$$&&&&&&&&&$$$$&&@@@@@@@@$%$&@@&&&@&$%;:':;:''`````'|%%%%%%$$&@@@@@&&&&@@#@@@@@@#@@@@@@@@@@@@@@@@#@@@@@@@@@#@@@@@@@@@@@@@@#@@@%
@@@@@@#####@$%%%$$$%%%||%%||||%%%%$%%$$$$$%%%%%%%$$$$&&&&&&&&&$$$$$$&&@@@@@@@&$;'''''':!%&&&&&&@@&%;'```:$&&%%%%%$$$&@@@@&&&&@@@@@@@@@#@@@@@##@@@@@@@@#@@@@@@@@@@@@@@#@@@@@@@@@#@@@%
$&@@@@######&&&&&$%%%%|%|||||||%%%%%$$$$$$$$$$$$$&&&&&&&&&&&&&&&&$$$$&&@@@@@@&$!''''''````````:!|$&&&&&&&$&&&$%%%%$$$&&@@@&&&&&@@@@&@@@@@@@@@#@@@@@@@@#@@@@@&&&@@@@@@@@@@@@@@@#@@@@$
$$$&@######@&&&&&&|!!!!!|||||||%%$$$$$$$$$$$$$$$&&&&&$$&&&&&&&&&&&&$$&&&@@@@@@&%;::''````````'':'``....`;|%$&&&$%%$$$$$&@@@&&&&&@@@@@@@@#@@@@@#@@@@@@@@@@@@@@&&@&&&&&&&&&@@@@@@@@@@$
$$$&@#####@&$$&&@#&|!!!!!|||||||%%%$$$$%%%%%$$$$$$$&&&&&&&&&&&&@@@@@&&&&&&@@@@@@@@@@@&&&&&&&&@@@@&&$$%||||%%%$$&&&$$$$$$$&@@@&&&&&@@@@@@@#@@@@@@@@@@@@@@@@@@@@&&@&&&&&&&&@@@@@@@@@#$
$$&@######@&$&@##@&$|!!!!|||||||%%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&$$&&&&&&@@&|'`````````':::;;;;;;!|%%%%%%%%$&@@&$$$$$$$&@@&&&&&@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@&&&&&&&&&@@@@@@@#@%
$&@######@&&&@##@$$$$|!!!||||||||%%%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&$&&&&&&&&@@$!:::'':::::::::::::''``.:%%$$$$$$&@@@&$$$$$&@@@&&&&@@@@@@@@@@@@#@@@@@@@@@@#@@@@#@@@@@@&&&@@@@@@@@@%
$&@######@&&@#@&$$$$&$|!!!||||||||%%%%%%%%%$$$$$&&&&&&&&&&&&&&&&&&&$$$&&&&&&&&&&&%;::::::::::::':''':'':::%&$$$$$$$$&&@@&$$$$$&@@@&&&&@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@%
&@#######@@@#@&$$$$$&&$|!!|||||||||%%%%%%$$$$$$$$$&&&&&&&&&&&&&&&$$$$$&&&&&&&&&&&$!''::::'''::;!|%%$&&@@@@&&@@$$%%$$$$&&@&&$$$$&@@@&&&&@@@@@@#@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@%
############&$$$$$$$&&&$|!!||||||||%%%%%%$$$$$$$$$$$$$$&&&&&$$$$$$$$$$&&&&&&&&&&&&@@@&&&&&&&@@@@@@&&&$$%|!;%@@@@&$$$$$$$$&@@&$$$$&@@@&&&@@@@@@@@@#@@@@@@#@@#@@@@@@@@@@@@@@@@@@@@@@@$
########@&$$$$$$$$$&&&&&$|!!||||||%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&@@&&&&&&&&&&&&&&$$$$$$$$$$&&&$$%!;:::|$&@@@@&$$$$$$$&@@&$$$&@@@&&&@@@@@@@@##@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@$
########@$%%%$$$$$$&&&&&&&%!||||%%%$$$%%%%%%%%%%%%%%%%%%%%%%%$$$$$&&&&&&&&&&@@@&&&&&&&&&&&&$$$$$$$$$$$$$&&%!!$$$$&@@@@&$$$$$$&@@@&&&&@@@&&@@@@@@@##@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@%
#######@&$$$$$$$$$$$$&$|!||%%%%||%%%%%%%%%%%%%%%%%$$$$$$&$$$$$&&&&&&&&@@@@&&&&&&&&&&&&&&&&&&&$$&&$$$$$$$$$&&&$&@&$$$&@@@&$$$$$$&@@@@&&@@@@&@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@#@@@@#@%
#######@$$$$$$%$$$$$$$&&$||||%%%%%%$$$$$$$$$$$$$$$$$$$$$$$&&&&&&&&&&@@&&&&&&&&&&&&$$$$$$&&&&$$$$$$$$$$$$$$$$$$&@@@@&$$$&@@@&$$$$&&&@@@&@@@@&&@@@@@###@@@@#@@@@@#@@@@@@@@@@@#@@@@#@@$
#######&$$$$$$$$$$&$$$$$&&&&&$%||%%%%%%$$$$$$$$$$$$$$$$$&&&&&&&&&&&@&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&@@@&$$$&@@@&$$&&&@@@@@@#@@@@@@@@##@@@@#@@@@@@@@@@@@@#@@@@@@##@##$
######@$$$$$$$$$$$$$$$$$$&&&&&&$||%%%%%%%$$$$$$$$$$$$$&&&&&&&&&@@&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&@@@@@&&$&&@@@&&&&&@@@@@##@@@@@@@##@@@###@@@@@@@@@@@@@@#@@@#@#@@%
######&$$$$$$$$$$$$$$$$$&&&&&&&&$%|%%%%%%%$$$$$$$$$$&&&&&&&&&&@&&@@&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$$$$$$$$$&@@@@@@&&&&&@@@&&&&@@@@@#@@@@@###@@@##@@@@@@@@@@@@@@#@@@####@#$
#####@$$$$$$$$$$$$$$$$$$$&&&&&&&&&%%%%%%%%%$$$$$$$$&&&&&&&&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$&$$$$$$$$$$$$$$$$$&&&@@@@@&&&&@@@@@@@@@@@@#@@@@###@@@$%%%%%%%%%%%%%$&@@#######$
#####@&$%$$$$$$$$$$$$$$$$$$&&&&&&&&$%%%%%%%%%%$$$$&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$$$$$$$$$$$$%$$$$$$$$$%%$$$$$$$$%%$$$$$%&@&&&&@@@@@&&@@@@@&&@@@@#@@@@###@&%%%%%%%%%%%%%%%%%&@##@##@%
####@@@@&$$$$$$$$$$$$$$$$$$&&&&&&&&&&%%%%%%%%%%$$&@&&&&$&&&$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||$$$$$$$$%%$$$$$|%$$$$$$$%%$&@@@&&&@@@@@@@@@@@@&@@@@@@@@##@&%%%%%%%%%%%%%%%%%%%$@@@@@%
####@@@@@@&$%$$$$$$$$$$$$$$$$$&&&&&&&&$%%%%%%%$&&&&&$$$$$$&$$$$$$$$$$$$$$$$$$$$$$$%%$$$%%%%|!|||$$$$%!|%%%$$&$$$$$$$$$$%%%$&@#@@@@&&@@@@@@@@@@@@@@##@@@@#@@@&$$%%%%%%%%|%%%%%|$@@@@$
###@@@@@@@@$$$%$$$$$$$$$$$$$&&&&&&&&&&&&%%%%%&&&&&$%%%$$&&&$$$$$$$$$%%%$$|%$$$%%%$%%|%%!;!||!!||%$$$$$$$%%$&$$&&$$$$$$$$$$%%$@@#@@@@@@&&@@@@@@@@#@@###@@@########@@$%%%%%%%|%%$&@##$
##@@@@@@@@@&$$$&$$$$$$$$$$$$$$$&&&&&&&&&&&%%%$&%|%%%%%$%%$$%%%%%%$$$%%%$$||%%%$$$$$%%%%%$$$$$%!!|%&&$$$$%|$$$$$$&$$$$$$$$$$$%$$&@@@@@@@@@@@@@@@##@@@@##@@####@@#######&%%%%%%%$@###$
#@@@@@@@@@@&&$$&$$$$$$$$$$$$$$$&&&&&&$||%%%$$%!;!;!|%%%%$%!||||%%%$$$||%$%%%%%%$$$$%$$%%%%$%$$$$||$&&$$&%|%$$$$$$$&$%%$%|%$$$$%$%$@@@@@@##@@@@@@@@@@########@##@@@######&$$&@@@@@##$
@$$&@@@@@@@&&$$$$$$$$$$$$$$$$$$&&&$&&&&$$&$$%!|%%%%%%%%%%||%%%%%%%%$$||%$$$$%%%%$$$%%$$%%%%%%%$$%|%&&$$&$%%$$$$$$$&&$%%&&&&$$$$$$$||$@@@@@@@@@@@@@@@@@@@####@@@@##@@@#@@@@@@@@@@@@@%
&$%%$$&&&$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&&&&|!|%%%%|%%%%%%$%%%%||||%$$%|%$&&$%%%%$$$$%$$%%%%$$$$$%|$&&&$&$$$&$&$$$$&&&$%$&&&$$&&&&&$%!!|$&@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@%
$$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&$&&&&&&$|!|||%%|%%%%%%$$%%%%||||%$$%%%$&&$%%%$$&&&$$$$$$$$$$$$$%%&&&&&$$&&$&$$&&&&&&&&&&&&&&&&&&&&$|!!!!$&@@@@@@@@@@@#####@######@##@@&@@@@@@@@@@$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&&$|!|||%$%%%%%%%$$$$%%%||||%$$%%%$&&$$%%$&&&&&$$$$$$$$$$$$%%&&&&&$$&&$&$$&&&&&&&&&&&&&&&&&&&&&&%!!!!|&&&@@@@@@#########@########@@##########$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&&&$&$%|!||%$$%%$%%%%$$$$$%%|||||$$$&$$&$$$%$&&&&&&$$$$$%$$$$$$%$&&&&&&&&&&&$$&&&&&&&&&&&&&&@@&&&&&@@$|!$@&||||%&@#@@####@########@@@@@@@#@&&@@##$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&&&$$&$%|!||%$$%%%%%%%$$$%$$%%||||%$&&&&&&$$$$$$&&&&&$%$$$%%$$$$$%$&&&&&&&&$$$$$&&&&&&&&&&&&&&@@@&&@@@@@&@@&|||||||||%&@###############@@@@@@##@@@@%
%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$&$&&$$$$%!!|%$$$%%%%%%$$$$%$$$%||||$&&$$&&$$$$$$$&&&$&$%%$%%%%%%$$%$$$&&&&&$$$$$$&&&&&&$&&&&&&&&&&&&&&&@@@@&||||||||||||$@#####@@@########@@@@@###@@$
%%%%%%%%$$$$$$$$$$$$$$$$$$$$$$$$$&&%%&%!!||%$$%%$$%%$$$$%%$$%%|!|%&&$%%&&$%%%%$$$&$|%$||$%%%%%%$$$$$$&&&&$$$$$$&&&&&&$$$&&&&&&&&&&@@&&&@@@&&%|||||||||%&@@##@$$@@@@########@@@@@@##$
;:''':;!|%%$$$$$$$$$$$$$$&&&&&&&&%%&&$!!|%%%%%%%$$$$$$$%%%$%%%|||$$&%!%&$%%%%|%%%&%!|$||%%%%%%%$$$$%%$&&$$$$$$$&&&&&&$$$$&&&&&&&&&&&&&&@@@@&&%|||||||%@@@@#@%|&#$||||%&@@@@@@@@@@@@$
.....  .`;|%%$$$$$$$$$$$&&&&&&$%%$&&$!;|%%|||%%$$&&&&$$%%$$%%%%%%%&%!;|$$%||||%%%$|;!%||$%$$$$$%%%%||$&$%%%$$$$&&&&&&$$$$&&&&&&&&&&&&&@@@@@@&&%|||||$@@@##&%|%@@%||||||||||&@@@@@@@%
........  `;|%$$$&&&&&&&&&&&$%$&&&&$|!|%%|!!|||$&$&&&$$%%%%%||||%$$|;;|%%|||||%$&&$|!|!!%%%%%%|!!|%!%$$%||%$&$&&&&&&&$$$$&&&&&&&&&&&&@@@@@@@@&&%|||$@@@##@$||$#&|||||||||||&#$|||||!
...    ..  `;|%$$$$&&&&&&$%$$&&&&&&||%%$||!!||$&$$$$$$%%%%%%||||%$%!:!!!%%$$$%%%%|!;;;;;!!!!!;;;||!%&%|%%%$&&$&&&&&&&$$$$&&&&&&&&&&&@@@@@@@@@&&$||$@##@@@%||%&@$||||||||||%&@$|||||!
       ..  .'!|%$$&&&&&&&&&&&&&&&&||$$&%||!||%&&$$$$$$%%$%||||||%|!;:;;;|%|!!!!!|!|$$&&&&$$$%!!!!;|&&$%%%$&$$$$%||&@&$$$$&&&&&&&&&@@@@@@@@@@@@&$|%@@@@#@%|||$@&%||||||||||%@@%|||||!
       ... .';|%$$&&&&&&&&&&&&&&&%%&$&&%|||||%&&$$$$$$%%$%%%||||%!;:::::::'':;!|%%%%$&@&&$%|!|%|;!$&$%|%%$$$$&$|!|$@@&$$$&@@@@@@@@@@@@@@@@@@@@&$$@@@#@&%|||%&#$|||||||||||$@&%|||||!
    ....   .:!|%$$&&&&&&&&&&&&&&$$&&&&$|||||%$@&$$&$$&&&$%|%%%%|;::''''''````'!!!;'`'%@&%|!::!;;!$$||%%%$&$$$$|!!|%&@@&&&&@@@@@@@@@@@@@@@@@@@@&&@@@@#@%||||$@@$|||||||||||$#&||||||!
     ..   .';!|%$$$&&&&&&&&&&&&$$&&&&&$$%||%%&@&$$&$$$$%|!;;;;:::'`````````````````';;:;!;'::::;%$|||!!|$$$%$%||||$@@@&&&@@@@@@@@@@@@@@@@@&&@&&&&&&@@@$%%||&#&%||||||||||%&#$||||||!
        .`:!!!|$$&&&&&&&&&&&&&&&&&&&&&&&$%$$$&@&&$&&$$|!|%$$$$%|;''``````````````':;!!!;::''':;!$%|$$%%$$$$$$%!!%&@@@@@@@@@@@@@@@@@@@@@@@@&&&&@&$$&@@@@@@@@@#&%||||||||||%@@$||||||!
;:''`'':;!!!!|%$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$&&&&&$|!%%%%$&$$|;'``````````````''''''''::::;|$&$$$%%$$%%$$$&@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@&$$$&&&@@@@@@@@@@@@@@&$%|||$@@$||||||!
|!;;;!!!!!!|%$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%!:;|!||!!:'''``````````````''''''''':;;|$$$$$%%$%$$$&&&&&@@@@@@@@@@@@@@@@@@@@@@@@&&&@&$$$&&&&&@@@@@##@@@@@&&@@@@@@#@&%|||||!
%|!!!!!!||%$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&&&$$$!';;;:'```''`````````````````'''''';;:|$$$$$$$$%$$$&@&&&&@@@#@@@@@@@@@@@@@@@@@@@&&@&$$$$$$$&&&@@@@##@%;''|&@@@@@@@#@@@@@@@%
&$%%%%%%$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&&@&&&$$$%;``'''``':'``````````````````'''':::;|$$$$$$$%$$$$&&&&&&@@@##@@@@@@@@@@@@@@@@@@&@&$$$&&&$$$&&&@@@@|:''':%@@@@@@@#@@@@@@@@%
@@&$$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&@@&&&$$$$%:``````';:'```...`````````````'''':;|$$$$$$%%$$$$&&&&&&&@@##@@#######@@#@@@@@@#@&$$&&&&&$%$$&&@@%:'::'!&@@@@&@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&&&&&&&$$%:``````':;:```..``````````````''':;|$$$$$$%%$$$&&&&&&&@@@####################@&$$&&$$$$$$$|;|&$!''':;$&&&&&&@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$&@&$&&&$&&&&&%'``````.``````....```````````'`'';|$&$$$%$$$$$$&&&&&@@@@@##################@$$$&&$$$$$|:':;%&$;''''|&&&&&&&&@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$%$&@@$$$$$&&&&&@@!````````.......````````````''`'':!%$&&&$$&&&&&&&&&&@@@#@@##############@@&$$$$&$$$$$$|:''|&&|''''!$&&&&&&@@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|;%&$&@$$$$$$&&&&&@@&;..``..........````````````''``'';%$&&&&&&&&&&&&&&@@@@@##@############@@@$$$$&$!|$$$$!:':%@%:``':%&&@@@@@@@@@@@@@@@@@%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$!!$&&$&&$|!|%$$$&&&@@@@$:.........``'''``':;:'`````````':!%$&&&&&&&@&&&&&@@@@@@@#@@#########@@@&$$$%!!$$$$$%;'';$&!``':%@@@@@@@@@@@@@@@@@@@&%
##@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|;%&&&&$%%$%!|%%$$$$&&@@@@@$;`.....`...````````````````````';|$&&&&&&&&@@@&&&@###@@@@#@&&##@@@@@&$$$$&&$$$$$$|'```!&%;|&&&&&@@@@@@@@@@@@@@@&&&&%
###&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%:|&&&&&$$||$&$|%%%$$&&&@@@@@@@@$;`........``'::'`...```'``````:|$$$&@@&$&@@@@@@&@#@@####@#&&#@$|%&$$%%&&$$$$%!'`.`:!$@@&&&&@@@@@@@@@@@@@@&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&&&&&&&&|:!&&&&&&$$%||$&&$%%%$$&&&&@@@@@@@@@@&%:`.................`'````:!;;|$$$&&@@&&&&@@@@&&@########@!':|&$$%%$|;:;;!|%%%%||$@@&&&&&&&@&&&&&&&&&&&&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&&&&$!:|&&&&&&&&$$%|%$&&&$%%%$&&&&&@@@@@@@@@@@@&&$;`..............``'';|!;;;;|%$$$$&@@@&&&@@&&$$&&@@@@##@&%||%%%$!:|%%%%%||%!|$@@@&&&&&&&&$$$$$$&&&&&&&&&&&&&%
###@&&&&&&&&&&&&&&&&&&&|:!$&&&&&&&&&&$%%%%$$&&&$%%$$$$&&@#@@@@@@@@@@@&&&&&&|'...........``:!!;;;;;!!;|$&$%|&@@@&&&&&$!|$$$&@@#@@&%%%%$|'':!%%%%|!|$&&@@&&&&&&&$%%%%$$$$$&&$$$$$$&&&%
###@&&&&&&&&&&&&&&&|:;%&&&&&&&&&&&&$$%%%%$$&&&&$$$$$$$$&@#@@@@@@@@@&&&&&&&&&&&&|'.....`;%%!!!!;;;!!!!;!%$$&$|%@@@@@&&@$;:::!|%$&$%%%$%:'``';!!|||%$&@@@&&&&&&$%%%%%%%$$$$$%%%%$$$$$|
###@&&&&&&&&&$|:;%&&&&&&&&&&&&&&&$$%%$%%$&&&&&&$$$$%$$$&@@@@@@@@@##@&&&&&&&&&&&&&&%|%&&&&&$|;;;;;;;;;;;;!$&$&$|!%&@@@@@@&%;::!$$$$$$%;:```````;||||%$&&$$$$$$%|%%%%%%%$$$%%%%%%%%$%|
###@&&$%|||$&&&&&&&&&&&&&&&&&&$$$$%%$$%$&&&&&&&$$$%%$$&&@@@@@@@@@@@##@&&&&&&&&&&&&&&&&&&&&@%;;;;;;;::;;;;!!$&&$$%!;|$$$&&&$&&&$$$$$%!|$&%:...`.`;|!|||!;!|||||||%%%%%%$%%%||||%%%%%|
&&@@&&&&&&&&&&&&&&&&&&&&&&&$$$$$$%%$$%$&&&&&&&&$%%%%$$&&@@@@@@@@@@@@#@&@@&&&&&&&&&&&&&@###&%;;;;;;::::;;;!!!!|$$$&&%!:;!$&&&@&$$$&@&&&$%$&|``..'%#@@&$%%||||!;:'`';|%%$%%|||||||||||
###@&&&&&&&&&&&&&&&&&&&&$$$$$$$$%%$&&$$&&&&&&&&$%%%%$$&&&@@@@@@@@@@@@@@&&&&@@@@@&&@####$;':!!;;;::::;;;;!;!;::::;%&&&&&$$$&@&$$$@@$$$$$&@@@@$%@#@@##@@&%%||||||||%%%|!'`:!||||||||||
###@&&&&&&&&&&&&&&&&&$$$$$$$$$$$$$$$%%$$$$&&&&@$%%%%$$&&&&&@@@@@@@@@&&&&@@&&&&&&&@@@@|:':;;!!;;:::::::;;!!;:::::::::':::';$$$$$&&$&&&@@@&&@@@@@#######@@##@&%||||||||%%%%|!''!|||||!
###@&&&&&&&&&&&&&&$$$$$$$$$$$&&$$$$$%%$$$$$&&&&&$%%$$$&&&&&$&&&@@@@&&&&&&&&&&&&@@@%:''':;;;;;:::::::::;;;:::::::::::::;;!%$$$$$|:::|$&&$&@@@@@&$&@#####@@@@####@&$%||%%%||||||;:!||!
###@&&&&&&&&&&&$$$$$$$$$$$&&&&&$$&&$%%$$$&&&&&&&&$%$$$$$&&&&&&&@@@#@&&&&&&&&@##$;''''':;;;;;:::::::::;!;:::::::::::::::;%&$$$$|''':;%&%!;:'''':|%$&@@@@#@@&&&@##@&&@@$|%%|||||||!:;|
:;$@@&&&&&&&$$$$$$$$$$$&&&&&&&&&$$&&$$&&&&&&&&&&&$%%$$$&&&&&&&&&&&&@@#######@|:'''''';!!!;::::::;;!!!!;::::::::::::::::|$$$$$!'::;!!%&|;;''''''''''';$&@@#@&&$$&@&&@#@@@#####@$%||;:
''''':|$&$$$$$$$$$$&&&&&&&&&&&&&&$$&$$&&&&&&&&&&&&&$$$$$&&$$&&&&&@@@@@&$%$%|:''''''':;:::::::::::::;;:::::::::::::::::|$$$$$!::;;;;|&%;;:''''''''''''':!$&@@@&$$$$&################$
'''''''''';%$$&&&&&&&&&&&&&&&&&&&&$$$$&&&&&&&&&&&&&&$$$$$&@@@@@###@&&$%;''''''''':::;;:::::::::::;;:::'':::::::::::':|$$$$$!::;:::|&%;;:''''''''''''''```:%&@@&&&$$$&##############$
'''''''''''':':|&&&&&&&&&&&&&&&&&&&&$%$&&&&&&&&&&&&&&$$$$$&@@&@@@&$$%%!:''''''::::::!;::::::::::;;::::::::::::::''':|$$$$$|;;:::;%&|::'''''''''''''`.....``;$@@&&&&$$$&@###########$
;:'''''''''''''':::!$&&&&&&&&&&&&&&&&&%|$&&&&&&&&&&&&&&$$$$&$$$$$$|:!|;':::::::::::;!;::::::::;;:::::::::::::''''':|$$$$$|;::::|&&|::'''''''''''``........`''!&@@&&&&$$$&@#########$
.';;;;;:'''''''''''':::;%&@&&&&&&&&&&&&%$&&$$$$&&&&&&$&@&&&$$$$%!:::!|;::::::::::::!!;::::::!;::::::::::::::''''':|&$$$$|;::::|&%;;:'``''''''''````......````'!$@@&&&&&$$$&@#######$
;;;:`.`:;;;;::'''''''''''':;%@@@&&&&&&&&$$$&&&&&&&&&&@@&!::':'':::::||;::::::::::::!!;:::;!!;;:::::::::::::::''':%&$$$$|;:::;%&|:::'`````````'''```..`...````''!$@@&&&&&&&$$&@#####$
;;;;;;;;;'..';;;;::''''''''''':|@@@@&&&&&&$%$&&&&&&&@@%:::::::::::::!|;:::::''''''';!;:;!!;:::::::::::::::::''':%&$$$%|;:::|&%;;:'''```````'''''``...      ```''!&@&&&&&&&&&&&&@###$
:::;;;;;;;;!;;;'':;;;;:'''''''''':!&@@@&&&&&$$&&&&@@@$;::::::::::::';|:``````````'';!;;;:'''```````````````''''|$$$$%|;::|&$!;;:'````````''::''``....      .``'':%@&&&&&&&&&&&&&&@#$
::::::::;;;;;;;;;;;;:'':;;:''''''''':;%@@@@&&&&$&@@@$;''''''':''`''`:|;````````````:!!:'''``.........``......`!$%%%%|;;|&$!:;'`````````'''::''.     ..    `''``''!$&&@@&&&&&&&&&&&&%
###@%!:::::::;;;;;;;;;;;;;;;;::'''''::::|&@@@&&&&&&%'```.....````''`'||'``````````';;'''``................. .!$%%%%|!%&$!:;:'``'''````'::::''.       ....``''``'''|@&&&@&&&@&&&&&&$|
####@&&&@&|;::::::;;;;;;;;;;;;;;;:'''''''::!&@@@@@%:````......```'```;%;`````````''''``.................   .!$%%%%%$&%;:::''```'''```'::::'`.         ...``'```''';$@&&&@@&&&&&&&&&%
####@&&&&&&&&&$!:::::::;;;;;;;;;;;;;:''''''':|@@@$;````.......``''```'!%;``````''''``.......      ....    .;%%%%%%$%;::'''`````''''`'::::`.             ...`````'''|@&&&&@@&&&&&&&&%
####@&&&&&&&&&&&&&&|;::::::;;;;;;;;;;;;:::'':;;%&;````.........``'````:||:```':''`......                .`:|%%%%%|;::''''``````'''''::::`.               ....```'''!$@&&&&@@&&&&&&&%
####@&&&&&&&&&&&&&&&&&&|::::::::;;;;;;;;;:::::;;'````..........``'`````:||:':''`......                .`'!$%%%%|;:''```````````'''''::;'.                 ......``':%@@&&&&&@&&&&&&%
####@&&&&&&&&&&&&&&&&&&&&&$!:::::::;;;;;;;;;;;;'`````..........`''``````:||:''`.  .                .``!$&$%%%%%;'''`````````````'':::;;`                   .....```'!&@&&&&&&@&&&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&|;:::::;;;;;;;;;:``````...........''````':':|%!'.                .``'|$&|;|%|%%%!''````...`````````':::;;`                    .....```'|@&&&&&&&@&&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&$!::::::;;;;;:``````....``......''``':'''':!|%;..         ..``:|%$|;::;|%||%%!'`````......```''`'':::;:'   .......           ....````:%@&&&&&&@@&&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%;:::::;;:```````....`.   ...`'':''`.  .':!||;````````';|%%|;::::';|%||%%;'```.........```'''''::::;'. ....````........  ......````:%@&&&&&&@@&&%
####@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|:::::'```````...``.   ..'::'``.   .```':;!||!;;!||!;::::''``';|%||%|;'```..........```'''''::::;:.....``````````...........`````;&&&&&&&@@@&%
*/

const int Mod=998244353;
pair<int,int> a[300005];
pair<int,int> b[300005],c[300005],d[300005];
int n;
int jc[300005];

bool fffff(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		b[i]=c[i]=d[i]=a[i];
	}
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=1LL*jc[i-1]*i%Mod;
	}
	int ans=0;
	sort(b+1,b+n+1);
	int lx=1;
	int now=1;
	for(int i=1;i<=n;i++){
		if(b[i].first!=b[i-1].first){
			now=1LL*now*jc[lx]%Mod;
			lx=1;
		}else{
			lx++;
		}
	}
	now=1LL*now*jc[lx]%Mod;
	ans=(ans+Mod-now)%Mod;
	bool can=1;
	for(int i=1;i<=n;i++){
		if(b[i].second<b[i-1].second){
			can=0;
		}
	}
	if(can){
		lx=1;
		now=1;
		for(int i=1;i<=n;i++){
			if(b[i]!=b[i-1]){
				now=1LL*now*jc[lx]%Mod;
				lx=1;
			}else{
				lx++;
			}
		}
		now=1LL*now*jc[lx]%Mod;
		ans=(ans+now)%Mod;
	}
	sort(c+1,c+n+1,fffff);
	lx=1;
	now=1;
	for(int i=1;i<=n;i++){
		if(c[i].second!=c[i-1].second){
			now=1LL*now*jc[lx]%Mod;
			lx=1;
		}else{
			lx++;
		}
	}
	now=1LL*now*jc[lx]%Mod;
	ans=(ans+Mod-now)%Mod;
	ans=(ans+jc[n])%Mod;
	printf("%d\n",ans);
	return 0;
}