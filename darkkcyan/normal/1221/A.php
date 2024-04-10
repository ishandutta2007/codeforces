<?php
$q = (int)fgets(STDIN);
while ($q--) {
    $n = (int)fgets(STDIN);
    $a = array_map(function ($x) { return (int)$x; }, explode(' ', trim(fgets(STDIN))));
    $cnt = array();
    foreach ($a as $i)
        $cnt[$i] ++;

    for ($i = 1; $i < 2048; $i *= 2) {
        if (!array_key_exists($i, $cnt)) continue;
        $cnt[$i * 2] += (int)($cnt[$i] / 2);
    }
    if (array_key_exists(2048, $cnt) && $cnt[2048] > 0) printf("YES\n");
    else printf("NO\n");
}