<?php
$input = [];
function readLine(){
    global $input;
    while(empty($input))$input=explode(' ',fgets(STDIN));
    $res = $input;
    $input = [];
    return array_map(function($x){return (int)$x;},$res);
}
function readToken(){
    global $input;
    while(empty($input))$input=explode(' ',fgets(STDIN));
    return array_shift($input);
}
function readInt(){
    return (int)readToken();
}
class Solution{
    public $debugMode;
    function __construct($flag){
        $this->debugMode = $flag;

    }
    function D($x){
        if($this->debugMode)var_dump($x);
    }
    function run(){
        list($b1,$q,$l,$m) = readLine();
        $a = readLine();
        $a = array_flip($a);
        if($q == 0) {
            if(abs($b1) > $l)echo "0\n";
            else if(!array_key_exists(0,$a)) echo "inf\n";
            else {
                if(array_key_exists($b1,$a)) echo "0\n";
                else echo "1\n";
            }

        } else if ($q == -1){
            if(abs($b1)>$l)echo "0\n";
            else if(array_key_exists($b1,$a) && array_key_exists(-$b1,$a))
                echo "0\n";
            else
                echo "inf\n";
        } else if ($q == 1){
            if(array_key_exists($b1,$a)||abs($b1)>$l)
                echo "0\n";
            else
                echo "inf\n";
        } else if($b1) {
            $ans=0;
            while(abs($b1)<=$l) {
                if(!array_key_exists($b1,$a))$ans++;
                $b1 = $b1 * $q;
            }
            echo "$ans\n";
        } else {
            if(array_key_exists(0,$a)){
                if(isset($a[$b1])||abs($b1)>$l)echo "0\n";
                else echo "1\n";
            }
            else echo "inf\n";
        }
    }
};
$caseNum=1;
for($caseId = 1;$caseId <= $caseNum; $caseId++){
    //echo 'Case #' . $caseId . ': ';
        $sol = new Solution(true);
            $sol->run();
           }