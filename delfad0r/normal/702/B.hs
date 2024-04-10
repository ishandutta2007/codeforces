import Data.Word
import qualified Data.IntMap as M

main =
    interact
    $ show
    . snd
    . foldr
        ( \x (m, a) ->
            ( M.insertWith (+) x 1 m
            , (+ a) . sum . map (flip (M.findWithDefault 0) m)
            $ takeWhile (> 0) [2 ^ k - x | k <- [30, 29 ..]])
        ) (M.empty, 0 :: Word64)
    . tail
    . map read
    . words