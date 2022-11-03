import Data.List
import Data.Map.Strict ((!))
import qualified Data.Map.Strict as Map

main = do
	(_ : xs) <- fmap (map read . words) getContents
	let m = Map.fromList $ fmap (\us@(u : _) -> (u, length us)) . group . sort $ xs
	foldl1 (>>) $ map (putStrLn . show) $ solve m []

solve m ans
	| Map.null m	= ans
	| otherwise		=
		let
			x		= fst $ Map.findMax m
			delList	= map (gcd x) ans
		in
			solve (foldl myDelete m (x : (delList ++ delList))) (x : ans)

myDelete m k = if (m ! k) == 1 then Map.delete k m else Map.adjust (subtract 1) k m