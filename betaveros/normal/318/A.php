<?php
// Hi chaotic
$localtest = ini_get("display_errors"); // normally true, codeforces sets to false
if ($localtest) {echo "derp";}

if ($localtest) {$stdin = fopen("localtest.txt", "r");} else {$stdin = fopen("php://stdin", "r");}
function g($num = -1) {
    global $stdin;
    $input = explode(" ", trim(fgets($stdin)));
    if ($num == -1) {return $input;} else {return $input[$num];}
}

$raw = g();
$n = $raw[0];
$k = $raw[1];

$parity = bcmod($n, 2);
$middle = bcdiv(bcadd($n, $parity), 2);

if (bccomp($k, $middle) != 1) {echo bcsub(bcmul(2, $k), 1);} else {echo bcmul(2, bcsub($k, $middle));}
?>