<?php
error_reporting(0);
//////////////////////// Class For Read Input --- @laurenceHR [02/2012] ////////////////////////////////////////////////////////////
class stdIn{var $ntxt = 0;var $nline = 0;var $arr_txt;var $arr_line;var $linex;var $liney;
function stdIn($local = false){if($local){$dir = fopen("input.txt", 'r');}else{$dir = fopen("php://stdin", 'r');}
$datatxt = stream_get_contents($dir);$del = Array("\n","\r","\n\r");$data = explode("\n",$datatxt);	$il = 0;$id = 0;
foreach($data as $line){if(strlen($line) > 0){$line = str_replace($del,'',$line);$dataex[] = $line;$text = explode(" ",$line);
foreach($text as $txt){$arr_txt[] = $txt;$this->linex[$id] = $il;$this->liney[$il] = $id;$id++;}}$il++;}$this->arr_line = $dataex;$this->arr_txt  = $arr_txt;}
function G(){$ret = $this->arr_txt[$this->ntxt++];$this->nline = $this->linex[$this->ntxt];return $ret;}
function GL(){$this->ntxt = $this->liney[$this->nline]+1;return $this->arr_line[$this->nline++];}} /*init*/ $dxs = new stdIn(false);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// DECLARE FUNCTIONS ///////////////////////////////////////
$s = $dxs->G();
/////////////////////////////////// MAIN CODE /////////////////////////////////////////////////
$now = -1;
$yes = true;
for($i = ord("a"); $i <= ord("z"); $i++) {
    $ret = strpos($s, chr($i));
    $lat = $now;
    if($ret === false) {
        $now = 100000;
    }
    else {
        $now = $ret;
    }
    if($now < $lat) {
        $yes = false;
    }
}
if($yes) {
    echo "YES";
}
else{
    echo "NO";
}
/////////////////////////////////////////////////////////////////////////////////////////////////
?>